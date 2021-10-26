/*
[boj] 에디터
https://www.acmicpc.net/problem/1406
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1406.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const len = parseInt(input[1]);
let command = [];
for (let i = 2; i < len + 2; i++) {
	command[i - 2] = input[i].split(" ");
}

const leftStack = [...input[0]];
const rightStack = [];
for (let i = 0; i < command.length; i++) {
	switch (command[i].join("")) {
		case "L":
			if (leftStack.length) rightStack.push(leftStack.pop());
			break;
		case "D":
			if (rightStack.length) leftStack.push(rightStack.pop());
			break;
		case "B":
			if (leftStack.length) leftStack.pop();
			break;
		default:
			const [cmd, char] = command[i];
			if (cmd === "P") leftStack.push(char);
			break;
	}
}
console.log(leftStack.join("") + rightStack.reverse().join(""));
