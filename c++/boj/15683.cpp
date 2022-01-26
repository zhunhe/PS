/*
 * 감시
 * https://www.acmicpc.net/problem/15683
 */

#include "bits/stdc++.h"
using namespace std;
typedef vector<vector<int>> vvi;

struct coor {
	int y, x;
};

#define EMPTY	0
#define CCTV1	1
#define CCTV2	2
#define CCTV3	3
#define CCTV4	4
#define CCTV5	5
#define WALL	6
#define WATCH	7

int n, m, ans = 1e9;
vector<coor> cctv;

void watchNorth(vvi &board, int y, int x) {
	for (int k = -1; y + k >= 0; k--) {
		if (board[y + k][x] == WALL) break;
		if (board[y + k][x] == EMPTY) board[y + k][x] = WATCH;
	}
}

void watchSouth(vvi &board, int y, int x) {
	for (int k = 1; y + k < n; k++) {
		if (board[y + k][x] == WALL) break;
		if (board[y + k][x] == EMPTY) board[y + k][x] = WATCH;
	}
}

void watchEast(vvi &board, int y, int x) {
	for (int k = 1; x + k < m; k++) {
		if (board[y][x + k] == WALL) break;
		if (board[y][x + k] == EMPTY) board[y][x + k] = WATCH;
	}
}

void watchWest(vvi &board, int y, int x) {
	for (int k = -1; x + k >= 0; k--) {
		if (board[y][x + k] == WALL) break;
		if (board[y][x + k] == EMPTY) board[y][x + k] = WATCH;
	}
}

vvi cctvType1(vvi board, int y, int x, int type) {
	switch (type) {
		case 0: watchNorth(board, y, x); break;
		case 1: watchEast(board, y, x); break;
		case 2: watchSouth(board, y, x); break;
		case 3: watchWest(board, y, x); break;
	}
	return board;
}

vvi cctvType2(vvi board, int y, int x, int type) {
	if (type == 0) {
		watchWest(board, y, x);
		watchEast(board, y, x);
	} else {
		watchNorth(board, y, x);
		watchSouth(board, y, x);
	}
	return board;
}

vvi cctvType3(vvi board, int y, int x, int type) {
	switch (type) {
		case 0:
			watchNorth(board, y, x);
			watchEast(board, y, x);
			break;
		case 1:
			watchEast(board, y, x);
			watchSouth(board, y, x);
			break;
		case 2:
			watchSouth(board, y, x);
			watchWest(board, y, x);
			break;
		case 3:
			watchWest(board, y, x);
			watchNorth(board, y, x);
			break;
	}
	return board;
}

vvi cctvType4(vvi board, int y, int x, int type) {
	switch (type) {
		case 0:
			watchWest(board, y, x);
			watchNorth(board, y, x);
			watchEast(board, y, x);
			break;
		case 1:
			watchNorth(board, y, x);
			watchEast(board, y, x);
			watchSouth(board, y, x);
			break;
		case 2:
			watchEast(board, y, x);
			watchSouth(board, y, x);
			watchWest(board, y, x);
			break;
		case 3:
			watchSouth(board, y, x);
			watchWest(board, y, x);
			watchNorth(board, y, x);
			break;
	}
	return board;
}

vvi cctvType5(vvi board, int y, int x) {
	watchNorth(board, y, x);
	watchEast(board, y, x);
	watchSouth(board, y, x);
	watchWest(board, y, x);
	return board;
}

void dfs(int depth, int start, vvi board) {
	if (depth == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == EMPTY)
					cnt++;
		ans = min(ans, cnt);
		return;
	}
	for (int i = start; i < cctv.size(); i++) {
		const int y = cctv[i].y;
		const int x = cctv[i].x;
		switch (board[y][x]) {
			case CCTV1:
				for (int k = 0; k < 4; k++)
					dfs(depth + 1, i + 1, cctvType1(board, y, x, k));
				break;
			case CCTV2:
				for (int k = 0; k < 2; k++)
					dfs(depth + 1, i + 1, cctvType2(board, y, x, k));
				break;
			case CCTV3:
				for (int k = 0; k < 4; k++)
					dfs(depth + 1, i + 1, cctvType3(board, y, x, k));
				break;
			case CCTV4:
				for (int k = 0; k < 4; k++)
					dfs(depth + 1, i + 1, cctvType4(board, y, x, k));
				break;
			case CCTV5:
				dfs(depth + 1, i + 1, cctvType5(board, y, x));
				break;
		}
	}
}

int main() {
	cin >> n >> m;
	vvi board(n, vector<int>(m));
	for (vector<int> &v : board) for (int &elem : v) cin >> elem;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			if (board[y][x] != EMPTY && board[y][x] != WALL)
				cctv.push_back({y, x});
	dfs(0, 0, board);
	cout << ans;
}