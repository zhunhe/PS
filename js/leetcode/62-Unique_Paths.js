/*
[leetcode] 62. Unique Paths
https://leetcode.com/problems/unique-paths/
*/

var uniquePaths = function (m, n) {
	// 시작점으로부터의 거리 담아줄 배열
	let dist = [...Array(m)].map((e) => Array(n).fill(0));

	for (let i = 0; i < m; i++) {
		for (let j = 0; j < n; j++) {
			if (i === 0 || j === 0) dist[i][j] = 1;
			else dist[i][j] = dist[i][j - 1] + dist[i - 1][j];
		}
	}
	return dist[m - 1][n - 1];
};
