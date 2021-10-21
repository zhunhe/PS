/*
[boj] 공유기 설치(2110)
https://www.acmicpc.net/problem/2110
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/2110.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const N = parseInt(input[0].split(" ")[0]);
const C = parseInt(input[0].split(" ")[1]);

let house = [];
for (let i = 1; i < N + 1; i++) {
	house[i - 1] = parseInt(input[i]);
}
house.sort((a, b) => a - b);

let left = 1;
let right = house[house.length - 1] - house[0];
let answer = 0;
while (left <= right) {
	let mid = parseInt((left + right) / 2);

	let cnt = 1;
	let point = house[0];
	for (let i = 0; i < house.length; i++) {
		if (house[i] - point >= mid) {
			cnt++;
			point = house[i];
		}
	}

	if (cnt >= C) {
		if (answer < mid) answer = mid;
		left = mid + 1;
	} else right = mid - 1;
}
console.log(answer);
