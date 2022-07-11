/*
 * 빙산
 * https://www.acmicpc.net/problem/2573
 */

#include "bits/stdc++.h"
using namespace std;

#define NOT_ICEBERG   0

int answer, height, width;
int iceberg[302][302];
int visited[302][302];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void bfs_count_iceberg(int y, int x) {
	queue<pair<int, int>> q;

	q.push({y, x});
	visited[y][x] = 1;
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++) {
			const int ny = y + dy[k];
			const int nx = x + dx[k];
			if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
			if (visited[ny][nx]) continue;
			if (iceberg[ny][nx] == NOT_ICEBERG) continue;
			q.push({ny, nx});
			visited[ny][nx] = 1;
		}
	}
}

int count_iceberg() {
	int count = 0;
	memset(visited, 0, sizeof(visited));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (visited[y][x]) continue;
			if (iceberg[y][x] == NOT_ICEBERG) continue;
			bfs_count_iceberg(y, x);
			++count;
		}
	}
	return count;
}

int count_melt(int y, int x) {
	int count = 0;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= height || nx >= width) continue;
		if (visited[ny][nx]) continue;
		if (iceberg[ny][nx] != NOT_ICEBERG) continue;
		++count;
	}
	return count;
}

void melt_iceberg() {
	memset(visited, 0, sizeof(visited));
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			if (visited[y][x]) continue;
			if (iceberg[y][x] == NOT_ICEBERG) continue;
			visited[y][x] = 1;
			iceberg[y][x] = max(iceberg[y][x] - count_melt(y, x), 0);
		}
	}
}

int main() {
	cin >> height >> width;
	for (int y = 0; y < height; y++)
		for (int x = 0; x < width; x++)
			cin >> iceberg[y][x];
	while (count_iceberg() == 1) {
		melt_iceberg();
		++answer;
	}
	if (count_iceberg() == 0)
		cout << 0 << '\n';
	else
		cout << answer << '\n';
}