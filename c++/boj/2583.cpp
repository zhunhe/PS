/*
 * 영역 구하기
 * https://www.acmicpc.net/problem/2583
 */

#include <bits/stdc++.h>

int m, n, k;
int length;
int map[100][100];
std::vector<int> answer;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void DFS(int y, int x) {
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
		if (map[ny][nx]) continue;
		map[ny][nx] = 1;
		length++;
		DFS(ny, nx);
	}
}

int main() {
	std::cin >> m >> n >> k;
	while (k--) {
		int s_x, s_y, e_x, e_y;
		std::cin >> s_x >> s_y >> e_x >> e_y;
		for (int i = s_y; i < e_y; i++) {
			for (int j = s_x; j < e_x; j++) {
				map[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) continue;
			map[i][j] = 1;
			length = 1;
			DFS(i, j);
			answer.push_back(length);
		}
	}
	sort(answer.begin(), answer.end());
	std::cout << answer.size() << '\n';
	for (auto elem : answer) std::cout << elem << ' ';
}
