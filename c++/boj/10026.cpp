/*
 * 적록색약
 * https://www.acmicpc.net/problem/10026
 */

#include "bits/stdc++.h"
using namespace std;

int n;
char board[101][101];
bool visited[101][101];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void dfs(int y, int x, char color, int r_g_weakness) {
	if (visited[y][x]) return;
	visited[y][x] = true;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
		if (visited[ny][nx]) continue;
		if (r_g_weakness) {
			if (color == 'B' && 'B' != board[ny][nx])
				continue;
			else if (color != 'B' && 'B' == board[ny][nx])
				continue;
		} else if (color != board[ny][nx])
			continue;
		dfs(ny, nx, color, r_g_weakness);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) cin >> board[i/n][i%n];
	for (int k = 0; k < 2; k++) {
		memset(visited, false, sizeof(visited));
		int ans = 0;
		for (int i = 0; i < n * n; i++)
			if (!visited[i/n][i%n]) {
				ans++;
				dfs(i/n, i%n, board[i/n][i%n], k);
			}
		cout << ans << ' ';
	}
}