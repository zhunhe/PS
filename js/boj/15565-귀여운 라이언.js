/*
[boj] 귀여운 라이언(15565)
https://www.acmicpc.net/problem/15565
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/15565.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const k = parseInt(input[0].split(" ")[1]);
const nums = input[1].split(" ").map((item) => +item);

let answer = Infinity;
let lionCnt = 0;
let left = 0;
for (let right = 0; right < n; right++) {
	if (nums[right] === 1) lionCnt++;
	while (lionCnt >= k) {
		answer = Math.min(answer, right - left + 1);
		if (nums[left] === 1) lionCnt--;
		left++;
	}
}
if (answer === Infinity) console.log(-1);
else console.log(answer);
