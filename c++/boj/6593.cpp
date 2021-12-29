/*
 * 상범 빌딩
 * https://www.acmicpc.net/problem/6593
 */

#include <bits/stdc++.h>
using namespace std;

#define START	'S'
#define GOAL	'E'
#define WALL	'#'
#define PATH	'.'

int l, r, c, sec;
char map[30][30][30];
const int dz[6] = {1,-1,0,0,0,0};
const int dy[6] = {0,0,-1,0,1,0};
const int dx[6] = {0,0,0,1,0,-1};

void BFS(int z, int y, int x) {
	queue<tuple<int, int, int> > q;
	q.push(make_tuple(z, y, x));
	map[z][y][x] = WALL;
	int L = 1;
	while (q.size()) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			tie(z,y,x) = q.front();
			q.pop();
			for (int k = 0; k < 6; k++) {
				const int nz = z + dz[k];
				const int ny = y + dy[k];
				const int nx = x + dx[k];
				if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
				if (map[nz][ny][nx] == GOAL) {
					sec = L;
					return;
				}
				if (map[nz][ny][nx] == WALL) continue;
				q.push(make_tuple(nz, ny, nx));
				map[nz][ny][nx] = WALL;
			}
		}
		L++;
	}
}

int main() {
	while (1) {
		bool end = false;
		cin >> l >> r >> c;
		if (!l && !r && !c) return 0;
		for (int i = 0; i < l; i++)
			for (int j = 0; j < r; j++)
				for (int k = 0; k < c; k++)
					cin >> map[i][j][k];
		sec = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					if (map[i][j][k] != START) continue;
					BFS(i, j, k);
					if (sec)
						cout << "Escaped in "<< sec <<" minute(s).\n";
					else
						cout << "Trapped!\n";
					end = true;
					if (end) break;
				}
				if (end) break;
			}
			if (end) break;
		}
	}
}
