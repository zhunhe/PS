/*
 * 로봇 청소기
 * https://www.acmicpc.net/problem/14503
 */

#include "bits/stdc++.h"
using namespace std;

#define NORTH	0
#define EAST	1
#define SOUTH	2
#define WEST	3

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

int main() {
	int n, m, r, c, d;	cin >> n >> m >> r >> c >> d;
	vector<vector<int>> coor(n, vector<int>(m));
	for (vector<int> &v : coor)
		for (int &elem : v)
			cin >> elem;
	int ans = 0;
	while (1) {
		if (coor[r][c] == 0) {
			coor[r][c] = 2;
			ans++;
		}
		int i;
		for (i = 0; i < 4; i++) {
			const int ny = r + dy[(d + 3) % 4];
			const int nx = c + dx[(d + 3) % 4];
			d = (d + 3) % 4;
			if (coor[ny][nx] != 0) continue;
			ans++;
			coor[ny][nx] = 2;
			r = ny;
			c = nx;
			break;
		}
		if (i == 4) {
			r -= dy[d];
			c -= dx[d];
			if (coor[r][c] == 1)
				break;
		}
	}
	cout << ans;
}