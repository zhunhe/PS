/*
 * 물 채우기
 * https://www.acmicpc.net/problem/2276
 */

#include "bits/stdc++.h"
using namespace std;
#define MAXN	301
int ans, m, n;
int bottle[MAXN][MAXN], visited[MAXN][MAXN];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
struct bottleData {
	int y, x, h;
	bool operator<(const bottleData &d) const {
		return d.h < h;
	}
};
priority_queue<bottleData> pq;

void dfs(int y, int x, int h) {
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (visited[ny][nx]) continue;
		visited[ny][nx] = 1;
		if (bottle[ny][nx] > h)
			pq.push({ny, nx, bottle[ny][nx]});
		else {
			ans += h - bottle[ny][nx];
			dfs(ny, nx, h);
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> bottle[i][j];
			if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
				pq.push({i, j, bottle[i][j]});
				visited[i][j] = 1;
			}
		}
	while (!pq.empty()) {
		bottleData tmp = pq.top(); pq.pop();
		dfs(tmp.y, tmp.x, tmp.h);
	}
	cout << ans;
}