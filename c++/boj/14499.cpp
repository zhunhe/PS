/*
 * 주사위 굴리기
 * https://www.acmicpc.net/problem/14499
 */

#include "bits/stdc++.h"
using namespace std;

#define BOTTOM	0
#define EAST	1
#define WEST	2
#define NORTH	3
#define SOUTH	4
#define TOP		5

const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, 1, -1, 0, 0};
vector<int> dice;

void rotateDice(int dir) {
	int tmp;
	switch (dir) {
		case EAST:
			tmp = dice[EAST];
			dice[EAST] = dice[TOP];
			dice[TOP] = dice[WEST];
			dice[WEST] = dice[BOTTOM];
			dice[BOTTOM] = tmp;
			break;
		case WEST:
			tmp = dice[WEST];
			dice[WEST] = dice[TOP];
			dice[TOP] = dice[EAST];
			dice[EAST] = dice[BOTTOM];
			dice[BOTTOM] = tmp;
			break;
		case NORTH:
			tmp = dice[NORTH];
			dice[NORTH] = dice[TOP];
			dice[TOP] = dice[SOUTH];
			dice[SOUTH] = dice[BOTTOM];
			dice[BOTTOM] = tmp;
			break;
		case SOUTH:
			tmp = dice[SOUTH];
			dice[SOUTH] = dice[TOP];
			dice[TOP] = dice[NORTH];
			dice[NORTH] = dice[BOTTOM];
			dice[BOTTOM] = tmp;
			break;
	}
}

int main() {
	int n, m, x, y, k;	cin >> n >> m >> y >> x >> k;
	vector<vector<int>> board(n, vector<int>(m));
	for (vector<int> &v : board) for (int &elem : v) cin >> elem;
	dice.resize(6);
	for (int i = 0; i < k; i++) {
		int dir;	cin >> dir;
		const int ny = y + dy[dir];
		const int nx = x + dx[dir];
		if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
		rotateDice(dir);
		cout << dice[TOP] << '\n';
		if (board[ny][nx] == 0)
			board[ny][nx] = dice[BOTTOM];
		else {
			dice[BOTTOM] = board[ny][nx];
			board[ny][nx] = 0;
		}
		y = ny;
		x = nx;
	}
}