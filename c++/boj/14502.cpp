/*
 * 연구소
 * https://www.acmicpc.net/problem/14502
 */

#include <bits/stdc++.h>
using namespace std;

#define VIRUS	2
#define WALL	1
#define EMPTY	0

int n, m;
int map_org[8][8];
int map[8][8];
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
vector<pair<int, int> > tmp;
queue<vector<pair<int, int> >> wall;


void BFS(int y, int x) {
	queue<pair<int, int> > q;
	q.push(make_pair(y, x));
	map[y][x] = 2;
	while (q.size()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			y = q.front().first; x = q.front().second; q.pop();
			for (int k = 0; k < 4; k++) {
				const int ny = y + dy[k];
				const int nx = x + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
				if (map[ny][nx] != EMPTY) continue;
				map[ny][nx] = 2;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

void reset_map() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			map[i][j] = map_org[i][j];
}

int count_empty() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != VIRUS) continue;
			BFS(i, j);
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == EMPTY) cnt++;
		}
	}
	return cnt;
}

void DFS(int L, int y) {
	if (L == 3) {
		wall.push(tmp);
		return;
	}
	for (int i = y; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map_org[i][j] == EMPTY) {
				map_org[i][j] = 1;
				tmp.push_back(make_pair(i, j));
				DFS(L + 1, i);
				map_org[i][j] = 0;
				tmp.pop_back();
			}
		}
	}
}

void set_wall() {
	for (int i = 0; i < 3; i++) {
		int y = wall.front()[i].first;
		int x = wall.front()[i].second;
		map[y][x] = WALL;
	}
	wall.pop();
}

int main() {
	int ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map_org[i][j];
	DFS(0, 0);

	while (!wall.empty()) {
		reset_map();
		set_wall();
		ans = max(ans, count_empty());
	}
	cout << ans;
}