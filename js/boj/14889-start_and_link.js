/*
[boj] 스타트와 링크(14889)
https://www.acmicpc.net/problem/14889
*/

const fs = require("fs");
const filePath =
	process.platform === "linux" ? "/dev/stdin" : "./testcase/14889.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const len = parseInt(input[0]);

arr = [...Array(len)];
for (let i = 1; i < len + 1; i++) {
	arr[i - 1] = input[i].split(" ").map((item) => +item);
}

function solution(len, arr) {
	const check = new Array(len).fill(0);
	let min = Number.MAX_SAFE_INTEGER;

	function dfs(L, s) {
		// 절반이 뽑혔다면
		if (L === len / 2) {
			const sTeam = [];
			const lTeam = [];
			let sSum = 0;
			let lSum = 0;
			for (let i = 0; i < len; i++) {
				// 체크 배열은 스타트 팀에 넣어주고
				// 체크 배열에 없으면 링크 팀에 넣어준다.
				if (check[i]) sTeam.push(i);
				else lTeam.push(i);
			}
			for (let i = 0; i < len / 2; i++) {
				for (let j = i + 1; j < len / 2; j++) {
					// (i,j), (j,i) 쌍을 계속 더해준다.
					sSum += arr[sTeam[i]][sTeam[j]] + arr[sTeam[j]][sTeam[i]];
					lSum += arr[lTeam[i]][lTeam[j]] + arr[lTeam[j]][lTeam[i]];
				}
			}
			min = Math.min(min, Math.abs(sSum - lSum));
			return;
		}

		for (let i = s; i < len; i++) {
			check[i] = 1;
			dfs(L + 1, i + 1);
			check[i] = 0;
		}
	}
	dfs(0, 0);
	return min;
}

console.log(solution(len, arr));
