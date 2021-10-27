/*
[boj] 선 긋기
https://www.acmicpc.net/problem/2170
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/2170.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0]);
const coordinate = [];
for (let i = 1; i < n + 1; i++) {
	coordinate[i - 1] = input[i].split(" ").map(Number);
}

coordinate.sort((a, b) => {
	if (a[0] === b[0]) return a[1] - b[1];
	else return a[0] - b[0];
});

const answer = [];
answer.push(coordinate[0]);
for (let i = 1; i < coordinate.length; i++) {
	const len = answer.length;
	let flag = true;
	for (let j = 0; j < len; j++) {
		const [x, y] = answer[j];
		if (coordinate[i][1] < x) continue;
		if (y < coordinate[i][0]) continue;
		answer[j][1] = Math.max(y, coordinate[i][1]);
		answer[j][0] = Math.min(x, coordinate[i][0]);
		flag = false;
		break;
	}
	if (flag) answer.push(coordinate[i]);
}

let result = 0;
for (let [from, to] of answer) {
	result += to - from;
}
console.log(result);
