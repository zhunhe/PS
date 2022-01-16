/*
 * 유기농 배추
 * https://www.acmicpc.net/problem/1012
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int m, n, k, ans = 0, y, x;	cin >> m >> n >> k;
		vector<vector<int>> board(n, vector<int>(m, 0));
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}
		const int dy[4] = {-1,0,1,0};
		const int dx[4] = {0,1,0,-1};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 0) continue;
				ans++;
				queue<pair<int, int>> q;
				q.push({i, j});
				board[i][j] = 0;
				while (!q.empty()) {
					y = q.front().first;
					x = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						const int ny = y + dy[k];
						const int nx = x + dx[k];
						if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
						if (board[ny][nx] == 0) continue;
						board[ny][nx] = 0;
						q.push({ny, nx});
					}
				}
			}
		}
		cout << ans << '\n';
	}
}