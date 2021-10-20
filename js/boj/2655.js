/*
[boj] 가장높은탑쌓기
https://www.acmicpc.net/problem/2655
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/2655.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// 벽돌 개수 세팅
const n = parseInt(input[0].split(" ")[0]);
// 넓이, 높이, 무게 세팅
let bricks = [];
for (let i = 1; i < n + 1; i++) {
	bricks[i - 1] = input[i].split(" ").map((item) => +item);
}
// enum
const AREA = 0;
const HEIGHT = 1;
const WEIGHT = 2;
const INDEX = 3;

// dp table은 i번째 벽돌을 포함하는 최대 높이
let dy = Array(bricks.length);
for (let i = 0; i < bricks.length; i++) {
	bricks[i].push(i + 1);
}

// 넓이 기준으로 내림차순 정렬
bricks.sort((a, b) => b[AREA] - a[AREA]);

// idx에는 높이의 합이 최대가 되는 벽돌들의 인덱스 값이 들어감
let idx = Array(bricks.length);
for (let i = 0; i < bricks.length; i++) {
	idx[i] = Array(1).fill(bricks[i][INDEX]);
}

// 전체 벽돌들을 탐색하면서 dy, idx에 값을 세팅
// dy === i번째 벽돌을 포함하는 높이의 합의 최대
// idx === 높이의 합의 최대일 때의 벽돌의 index 번호 (1 ~ N)
for (let i = 0; i < bricks.length; i++) {
	// 현재 벽돌을 포함해야 하므로 초기값으로 현재 벽돌 높이 설정
	dy[i] = bricks[i][HEIGHT];
	// 현재 인덱스의 벽돌을 포함하는 벽돌들의 높이의 합의 최대값, 그 벽돌들의 인덱스 번호를 세팅
	for (let j = 0; j < i; j++) {
		// 앞에 있는 벽돌이 더 가벼우면 continue (넓이를 내림차순으로 정렬해둠, === 포함해도 조건에 의해 결과는 같음)
		if (bricks[i][WEIGHT] > bricks[j][WEIGHT]) continue;
		// 높이의 합이 최대가 안될 경우 continue
		if (dy[i] >= dy[j] + bricks[i][HEIGHT]) continue;

		// dy에 높이 합을 갱신하고
		dy[i] = dy[j] + bricks[i][HEIGHT];
		// 가장 가벼운 현재 벽돌의 인덱스를 저장
		idx[i] = [bricks[i][INDEX]];
		// 앞에서 찾은 벽돌들의 인덱스를 저장
		for (const x of idx[j]) {
			idx[i].push(x);
		}
	}
}

let answer = [];
let height = Number.MIN_SAFE_INTEGER;
// 최대 높이값으로 갱신해 나가면서 그에 해당하는 벽돌 인덱스 번호를 세팅
for (let i = 0; i < dy.length; i++) {
	if (height >= dy[i]) continue;
	answer = idx[i];
	height = dy[i];
}

// 정답출력: 길이, 벽돌 인덱스
console.log(answer.length);
for (const x of answer) console.log(x);
