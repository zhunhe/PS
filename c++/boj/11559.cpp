/*
 * Puyo Puyo
 * https://www.acmicpc.net/problem/11559
 */

#include "bits/stdc++.h"
using namespace std;

#define EMPTY	'.'
#define RED		'R'
#define GREEN	'G'
#define BLUE	'B'
#define PURPLE	'P'
#define YELLOW	'Y'

#define HEIGHT	12
#define WIDTH	6

queue<pair<int, int>> q;
char board[12][6];
bool visited[12][6];
int len, ans;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void findSamePuyo(int y, int x, char color) {
	if (visited[y][x]) return;
	visited[y][x] = true;
	len++;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || ny >= HEIGHT || nx < 0 || nx >= WIDTH) continue;
		if (board[ny][nx] != color) continue;
		if (visited[ny][nx]) continue;
		findSamePuyo(ny, nx, color);
	}
}

void deletePuyo(int y, int x, char color) {
	if (board[y][x] == EMPTY) return;
	board[y][x] = EMPTY;
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || ny >= HEIGHT || nx < 0 || nx >= WIDTH) continue;
		if (board[ny][nx] != color) continue;
		deletePuyo(ny, nx, color);
	}
}

void puyoDown() {
	for (int x = 0; x < WIDTH; x++) {
		int bottom = HEIGHT - 1;
		while (bottom && board[bottom][x] != EMPTY)
			bottom--;
		for (int y = bottom - 1; y >= 0; y--) {
			if (board[y][x] == EMPTY) continue;
			board[bottom--][x] = board[y][x];
			board[y][x] = EMPTY;
		}
	}
}

int main() {
	for (int y = 0; y < HEIGHT; y++)
		for (int x = 0; x < WIDTH; x++)
			cin >> board[y][x];
	queue<pair<int, int>> puyoQ;
	while (1) {
		memset(visited, false, sizeof(visited));
		for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (board[y][x] == EMPTY) continue;
				if (visited[y][x]) continue;
				len = 0;
				findSamePuyo(y, x, board[y][x]);
				if (len > 3)
					puyoQ.push({y, x});
			}
		}
		if (puyoQ.empty()) {
			cout << ans;
			return 0;
		}
		while (!puyoQ.empty()) {
			const int y = puyoQ.front().first;
			const int x = puyoQ.front().second;
			puyoQ.pop();
			deletePuyo(y, x, board[y][x]);
		}
		puyoDown();
		ans++;
	}
}