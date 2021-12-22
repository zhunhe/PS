/*
 * ¿¬±¸¼Ò 2
 * https://www.acmicpc.net/problem/17141
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define EMPTY	0
#define WALL	1
#define VIRUS	2

#define EMPTY_CHAR	' '
#define WALL_CHAR	'-'
#define VIRUS_CHAR	'0'

int n, m, ans = 1e9, sec;
int map_org[50][50];
char map[50][50];
vector<pair<int, int> > coor_virus;
vector<pair<int, int> > tmp;
queue<vector<pair<int, int> >> virus;

void DFS(int L, int y, int x) {
	if (L == m) {
		virus.push(tmp);
		return;
	}
	for (int i = y; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map_org[i][j] != VIRUS) continue;
			if (i == y && j < x) continue;
			map_org[i][j] = EMPTY;
			tmp.push_back(make_pair(i, j));
			DFS(L + 1, i, j);
			map_org[i][j] = VIRUS;
			tmp.pop_back();
		}
	}
}

void reset_map() {
	for (int i = 0; i < n * n; i++) {
		if (map_org[i/n][i%n] == WALL) map[i/n][i%n] = WALL_CHAR;
		else map[i/n][i%n] = EMPTY_CHAR;
	}
}

void set_virus() {
	for (int i = 0; i < m; i++) {
		int y = virus.front()[i].first;
		int x = virus.front()[i].second;
		map[y][x] = VIRUS_CHAR;
	}
	virus.pop();
}

bool no_empty() {
	for (int i = 0; i < n * n; i++)
		if (map[i/n][i%n] == EMPTY_CHAR)
			return false;
	return true;
}

void BFS() {
	const int dy[4] = {-1,0,1,0};
	const int dx[4] = {0,1,0,-1};
	queue<pair<int, int> > q;
	for (int i = 0; i < n * n; i++)
		if (map[i/n][i%n] == VIRUS_CHAR)
			q.push(make_pair(i/n, i%n));
	sec = 0;
	while (q.size()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int y = q.front().first; int x = q.front().second; q.pop();
			for (int k = 0; k < 4; k++) {
				const int ny = y + dy[k];
				const int nx = x + dx[k];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (map[ny][nx] != EMPTY_CHAR) continue;
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
		sec++;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n * n; i++) cin >> map_org[i / n][i % n];
	DFS(0, 0, 0);
	while (!virus.empty()) {
		reset_map();
		set_virus();
		BFS();
		if (no_empty()) ans = min(ans, sec);
	}
	if (ans == 1e9) cout << -1;
	else cout << ans - 1;
}