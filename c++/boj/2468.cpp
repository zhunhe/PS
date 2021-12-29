/*
 * 안전 영역
 * https://www.acmicpc.net/problem/2468
 */

#include <bits/stdc++.h>
using namespace std;

int n, min_level = 1e9, max_level, level, cnt, answer;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

int map[100][100];
bool visit[100][100];

void DFS(int y, int x) {
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx] < level) continue;
		if (visit[ny][nx]) continue;
		visit[ny][nx] = true;
		DFS(ny, nx);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> map[i / n][i % n];
		min_level = min(min_level, map[i / n][i % n]);
		max_level = max(max_level, map[i / n][i % n]);
	}
	for (level = min_level; level <= max_level; level++) {
		for (int i = 0; i < n * n; i++) visit[i / n][i % n] = false;
		cnt = 0;
		for (int i = 0; i < n * n; i++) {
			if (map[i / n][i % n] < level) continue;
			if (visit[i / n][i % n]) continue;
			visit[i / n][i % n] = true;
			cnt++;
			DFS(i / n, i % n);
		}
		answer = max(answer, cnt);
	}
	cout << answer;
}