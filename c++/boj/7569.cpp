/*
 * 토마토
 * https://www.acmicpc.net/problem/7569
 */

#include "bits/stdc++.h"
using namespace std;

int d, h, w, answer;
int box[102][102][102];
int visited[102][102][102];
const int dz[6] = {-1, 1, 0, 0, 0, 0};
const int dy[6] = {0, 0, -1, 0, 1, 0};
const int dx[6] = {0, 0, 0, 1, 0, -1};
struct coor {
	int z, y, x;
};

bool all_riped() {
	for (int z = 0; z < d; z++)
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				if (box[z][y][x] == 0)
					return false;
	return true;
}

int main() {
	cin >> w >> h >> d;

	queue<coor> q;
	for (int z = 0; z < d; z++) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				cin >> box[z][y][x];
				if (box[z][y][x] == 1)
					q.push({z, y, x});
			}
		}
	}

	while (!q.empty()) {
		coor cur = q.front(); q.pop();
		for (int k = 0; k < 6; k++) {
			const int nz = cur.z + dz[k];
			const int ny = cur.y + dy[k];
			const int nx = cur.x + dx[k];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= d || ny >= h || nx >= w) continue;
			if (box[nz][ny][nx] != 0) continue;
			box[nz][ny][nx] = box[cur.z][cur.y][cur.x] + 1;
			answer = max(answer, box[nz][ny][nx]);
			q.push({nz, ny, nx});
		}
	}
	if (!all_riped())
		cout << -1 << '\n';
	else if (answer == 0)
		cout << 0 << '\n';
	else
		cout << answer - 1 << '\n';
}