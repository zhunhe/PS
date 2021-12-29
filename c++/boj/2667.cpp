/*
 * 단지번호붙이기
 * https://www.acmicpc.net/problem/2667
 */

#include <bits/stdc++.h>

int n;
int length;
int map[25][25];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
std::vector<int> answer;

void DFS(int y, int x) {
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (map[ny][nx] == 0) continue;
		map[ny][nx] = 0;
		length++;
		DFS(ny, nx);
	}
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string s;	std::cin >> s;
		for (int j = 0; j < n; j++)
			map[i][j] = s[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!map[i][j]) continue;
			map[i][j] = 0;
			length = 1;
			DFS(i, j);
			answer.push_back(length);
		}
	}
	sort(answer.begin(), answer.end());
	std::cout << answer.size() << '\n';
	for (auto num : answer) std::cout << num << '\n';
}