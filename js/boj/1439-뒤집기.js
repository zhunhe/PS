/*
[boj] 뒤집기
https://www.acmicpc.net/problem/1439
*/

// 파일로부터 값 입력 받기
const { on } = require("events");
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/1439.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const digits = input.join("");

let zeroCnt = 0;
let oneCnt = 0;
for (let i = 0; i < digits.length; i++) {
	if (i === 0 || digits[i] !== digits[i - 1]) {
		if (digits[i] === "0") zeroCnt++;
		else oneCnt++;
		continue;
	}
}
if (zeroCnt >= oneCnt) console.log(oneCnt);
else console.log(zeroCnt);
