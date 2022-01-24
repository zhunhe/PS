/*
 * 전구 끄기
 * https://www.acmicpc.net/problem/14927
 */

#include "bits/stdc++.h"
using namespace std;

#define ON		1
#define OFF		0
int n, result = 1e9;
vector<vector<int>> board;

void Push(int y, int x) {
	const int dy[4] = {-1,0,1,0};
	const int dx[4] = {0,1,0,-1};
	board[y][x] ^= 1;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		board[ny][nx] ^= 1;
	}
}

bool Check() {
	for (int x = 0; x < n; x++)
		if (board[n - 1][x] == ON)
			return false;
	return true;
}

void dfs(int index, int click) {
	if (index == n * n) {
		if (Check())
			result = min(result, click);
		return;
	}
	if (index / n == 0) {
		dfs(index + 1, click);
		Push(index / n, index % n);
		dfs(index + 1, click + 1);
		Push(index / n, index % n);
	} else {
		if (board[index / n - 1][index % n] == OFF)
			dfs(index + 1, click);
		else {
			Push(index / n, index % n);
			dfs(index + 1, click + 1);
			Push(index / n, index % n);
		}
	}
}

int main() {
	cin >> n;
	board.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	dfs(0, 0);
	cout << (result == 1e9 ? -1 : result);
}