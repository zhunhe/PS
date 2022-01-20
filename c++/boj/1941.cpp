/*
 * 소문난 칠공주
 * https://www.acmicpc.net/problem/1941
 */

#include "bits/stdc++.h"
using namespace std;

#define LEN		5
int ans;
vector<vector<char>> board;
vector<vector<bool>> picked;

bool bfs() {
	const int dy[4] = {-1,0,1,0};
	const int dx[4] = {0,1,0,-1};
	int y, x, len = 0;
	vector<vector<bool>> visited;
	visited.resize(LEN, vector<bool>(LEN));
	for (int i = 0; i < LEN * LEN; i++) {
		if (!picked[i/LEN][i%LEN]) continue;
		y = i / LEN;
		x = i % LEN;
		break;
	}
	queue<pair<int, int>> q;
	len++;
	visited[y][x] = true;
	q.push({y, x});
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			const int ny = y + dy[k];
			const int nx = x + dx[k];
			if (ny < 0 || ny >= LEN || nx < 0 || nx >= LEN) continue;
			if (!picked[ny][nx]) continue;
			if (visited[ny][nx]) continue;
			len++;
			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	return (len == 7 ? true : false);
}

bool isValid() {
	int sCount = 0;
	for (int i = 0; i < LEN * LEN; i++)
		if (picked[i/LEN][i%LEN] && board[i/LEN][i%LEN] == 'S')
			sCount++;
	return (sCount >= 4 ? true : false);
}

void dfs(int depth, int start) {
	if (depth == 7) {
		if (isValid() && bfs())
			ans++;
		return;
	}
	for (int i = start; i < LEN * LEN; i++) {
		picked[i/LEN][i%LEN] = true;
		dfs(depth + 1, i + 1);
		picked[i/LEN][i%LEN] = false;
	}
}

int main() {
	board.resize(LEN, vector<char>(LEN));
	for (vector<char> &v : board) for (char &elem : v) cin >> elem;
	picked.resize(LEN, vector<bool>(LEN));
	dfs(0, 0);
	cout << ans;
}