/*
 * 뱀
 * https://www.acmicpc.net/problem/3190
 */

#include "bits/stdc++.h"
using namespace std;
#define MAXN	100
#define EMPTY	0
#define APPLE	1
#define SNAKE	2
#define LEFT	'L'
#define RIGHT	'D'
struct cmdData {
	int time;
	char dir;
};
struct coor {
	int y, x;
};
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
int n, k, t;
int board[MAXN][MAXN];
queue<cmdData> cmd;
deque<coor> snake;

void setApple() {
	while (k--) {
		int y, x;   cin >> y >> x;
		board[y - 1][x - 1] = APPLE;
	}
}

void setCommand() {
	while (k--) {
		int t; char dir; cin >> t >> dir;
		cmd.push({t, dir});
	}
}

int getDirection(int t, int dir) {
	if (!cmd.empty() && t == cmd.front().time) {
		if (cmd.front().dir == LEFT)
			dir = (dir + 3) % 4;
		else
			dir = (dir + 1) % 4;
		cmd.pop();
	}
	return dir;
}

int main() {
	cin >> n >> k;
	setApple();
	cin >> k;
	setCommand();
	int dir = EAST;
	coor cur = {0, 0};
	board[cur.y][cur.x] = SNAKE;
	snake.push_front(cur);
	while (1) {
		dir = getDirection(t, dir);
		coor next = {cur.y + dy[dir], cur.x + dx[dir]};
		if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= n) break;
		if (board[next.y][next.x] == SNAKE) break;
		if (board[next.y][next.x] == APPLE) {
			board[next.y][next.x] = SNAKE;
			snake.push_front(next);
		} else {
			board[next.y][next.x] = SNAKE;
			snake.push_front(next);
			board[snake.back().y][snake.back().x] = EMPTY;
			snake.pop_back();
		}
		cur = next;
		t++;
	}
	cout << t + 1;
}