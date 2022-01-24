/*
 * 불 끄기
 * https://www.acmicpc.net/problem/14939
 */

#include "bits/stdc++.h"
using namespace std;

#define LEN		10
#define ON		1
#define OFF		0
int result = 1e9;
vector<vector<int>> board;

void Push(int y, int x) {
	const int dy[4] = {-1,0,1,0};
	const int dx[4] = {0,1,0,-1};
	board[y][x] ^= 1;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || ny >= LEN || nx < 0 || nx >= LEN) continue;
		board[ny][nx] ^= 1;
	}
}

bool Check() {
	for (int x = 0; x < LEN; x++)
		if (board[LEN - 1][x] == ON)
			return false;
	return true;
}

void dfs(int index, int click) {
	if (index == LEN * LEN) {
		if (Check())
			result = min(result, click);
		return;
	}
	if (index / LEN == 0) {
		dfs(index + 1, click);
		Push(index / LEN, index % LEN);
		dfs(index + 1, click + 1);
		Push(index / LEN, index % LEN);
	} else {
		if (board[index / LEN - 1][index % LEN] == OFF)
			dfs(index + 1, click);
		else {
			Push(index / LEN, index % LEN);
			dfs(index + 1, click + 1);
			Push(index / LEN, index % LEN);
		}
	}
}

int main() {
	board.resize(LEN, vector<int>(LEN));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			char tmp;	cin >> tmp;
			if (tmp == 'O') board[i][j] = ON;
			else board[i][j] = OFF;
		}
	}
	dfs(0, 0);
	cout << (result == 1e9 ? -1 : result);
}