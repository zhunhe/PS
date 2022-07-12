/*
 * 벽 부수고 이동하기
 * https://www.acmicpc.net/problem/2206
 */

#include "bits/stdc++.h"
using namespace std;

#define WALL	'1'
#define EMPTY	'0'

int h, w;
char board[1002][1002];
int dist[1002][1002][2];
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

struct boardData {
	int y, x, broken;
};

int main() {
	cin >> h >> w;
	for (int y = 0; y < h; y++)
		for (int x = 0; x < w; x++)
			cin >> board[y][x];
	queue<boardData> q;
	q.push({0, 0, false});
	dist[0][0][0] = 1;
	while (!q.empty()) {
		boardData cur = q.front();	q.pop();
		if (cur.y == h - 1 && cur.x == w - 1) {
			cout << dist[cur.y][cur.x][cur.broken] << '\n';
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			boardData next = {cur.y + dy[k], cur.x + dx[k], cur.broken};
			if (next.y < 0 || next.x < 0 || next.y >= h || next.x >= w) continue;
			if (dist[next.y][next.x][next.broken]) continue;
			if (board[next.y][next.x] == EMPTY) {
				dist[next.y][next.x][next.broken] = dist[cur.y][cur.x][cur.broken] + 1;
				q.push(next);
			}
			if (board[next.y][next.x] == WALL && cur.broken == 0) {
				dist[next.y][next.x][1] = dist[cur.y][cur.x][0] + 1;
				next.broken = 1;
				q.push(next);
			}
		}
	}
	cout << -1 << '\n';
}