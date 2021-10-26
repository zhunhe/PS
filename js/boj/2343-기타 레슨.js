/*
[boj] 기타레슨
https://www.acmicpc.net/problem/2343
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/2343.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const m = parseInt(input[0].split(" ")[1]);
let lecture = input[1].split(" ").map((item) => +item);

let left = 0;
let right = 0;
for (let l of lecture) right += l;

function isValidLength(len) {
	let answer = 0;
	let sum = 0;

	for (let i = 0; i < lecture.length; i++) {
		if (lecture[i] > len) return false;
		if (lecture[i] + sum <= len) {
			if (sum === 0) answer++;
			sum += lecture[i];
		} else {
			answer++;
			sum = lecture[i];
		}
	}
	if (answer <= m) return true;
	else return false;
}

let answer = Infinity;
while (left <= right) {
	let mid = parseInt((left + right) / 2);
	if (isValidLength(mid)) {
		right = mid - 1;
		answer = Math.min(answer, mid);
	} else {
		left = mid + 1;
	}
}
console.log(answer);
