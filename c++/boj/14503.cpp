/*
 * 로봇 청소기
 * https://www.acmicpc.net/problem/14503
 */

#include "bits/stdc++.h"
using namespace std;

#define EMPTY	0
#define WALL	1
#define PASSED	2

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
	int n, m, y, x, d;	cin >> n >> m >> y >> x >> d;
	vector<vector<int>> coor(n, vector<int>(m));
	for (vector<int> &v : coor) for (int &elem : v) cin >> elem;
	int ans = 0;
	while (1) {
		if (coor[y][x] == EMPTY) {
			coor[y][x] = PASSED;
			ans++;
		}
		int i;
		for (i = 0; i < 4; i++) {
			const int ny = y + dy[(d + 3) % 4];
			const int nx = x + dx[(d + 3) % 4];
			d = (d + 3) % 4;
			if (coor[ny][nx] != EMPTY) continue;
			y = ny;
			x = nx;
			break;
		}
		if (i == 4) {
			y -= dy[d];
			x -= dx[d];
			if (coor[y][x] == WALL)
				break;
		}
	}
	cout << ans;
}