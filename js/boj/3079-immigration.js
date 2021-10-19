/*
[boj] 입국심사(3079)
https://www.acmicpc.net/problem/3079
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/3079.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const numOfOfficers = parseInt(input[0].split(" ")[0]);
const passengers = parseInt(input[0].split(" ")[1]);

let officer = [];
for (let i = 1; i < numOfOfficers + 1; i++) {
	officer[i - 1] = parseInt(input[i]);
}

let left = 1;
let right = Math.max(...officer) * passengers;

let answer;
while (left <= right) {
	let mid = Math.floor((left + right) / 2);

	let people = 0;
	for (let x of officer) {
		people += Math.floor(mid / x);
	}
	if (people >= passengers) {
		answer = mid;
		right = mid - 1;
	} else {
		left = mid + 1;
	}
}
console.log(answer);
