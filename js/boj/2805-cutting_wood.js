/*
[boj] 나무 자르기(2805번)
https://www.acmicpc.net/problem/2805
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/2805.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const m = parseInt(input[0].split(" ")[1]);

let tree = input[1].split(" ").map((item) => +item);

let left = 0;
let right = Number.MAX_SAFE_INTEGER;

let answer = 0;

while (left <= right) {
	let mid = parseInt((left + right) / 2);

	let cut = 0;
	for (let i = 0; i < n; i++) {
		// 자를 수 있는 나무의 길이를 모두 저장
		if (tree[i] >= mid) cut += tree[i] - mid;
	}
	// 자른 나무의 길이가 m의 길이보다 큰 경우
	if (cut >= m) {
		left = mid + 1;
		answer = mid;
	} else right = mid - 1;
}

console.log(answer);
