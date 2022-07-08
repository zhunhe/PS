/*
 * 토마토
 * https://www.acmicpc.net/problem/7576
 */

#include "bits/stdc++.h"
using namespace std;

int h, w, answer;
int box[1002][1002];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

bool all_riped() {
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (box[y][x] == 0) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> w >> h;
	queue<pair<int, int>> q;

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> box[y][x];
			if (box[y][x] == 1)
				q.push({y, x});
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			const int ny = cur.first + dy[k];
			const int nx = cur.second + dx[k];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (box[ny][nx] != 0) continue;
			box[ny][nx] = box[cur.first][cur.second] + 1;
			answer = max(answer, box[ny][nx]);
			q.push({ny, nx});
		}
	}

	if (!all_riped()) {
		cout << -1 << '\n';
	} else if (answer == 0)
		cout << 0 << '\n';
	else
		cout << answer - 1 << '\n';
}