/*
 * 벽 부수고 이동하기 4
 * https://www.acmicpc.net/problem/16946
 */

#include "bits/stdc++.h"
using namespace std;

struct coor {
	int y, x;
};
int n, m, idx;
vector<vector<int>> board;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int bfs(int y, int x) {
	queue<coor> q;
	q.push({y, x});
	board[y][x] = idx;
	int len = 1;
	while (!q.empty()) {
		y = q.front().y;
		x = q.front().x;
		q.pop();
		for (int k = 0; k < 4; k++) {
			const int ny = y + dy[k];
			const int nx = x + dx[k];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] != -1) continue;
			board[ny][nx] = idx;
			len++;
			q.push({ny, nx});
		}
	}
	return len;
}

int main() {
	cin >> n >> m;
	board.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char tmp;	cin >> tmp;
			if (tmp == '0') board[i][j] = -1;
			else board[i][j] = 0;
		}
	}
	vector<int> len;
	len.push_back(0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != -1) continue;
			idx++;
			len.push_back(bfs(i, j));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0) {
				cout << 0;
				continue;
			}
			set<int> tmp;
			for (int k = 0; k < 4; k++) {
				const int ny = i + dy[k];
				const int nx = j + dx[k];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
				tmp.insert(board[ny][nx]);
			}
			int sum = 0;
			for (auto elem : tmp)
				sum += len[elem];
			cout << (sum + 1) % 10;
		}
		cout << '\n';
	}
}