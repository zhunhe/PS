/*
 * 구간 합 구하기 3
 * https://www.acmicpc.net/problem/11658
 */

#include "bits/stdc++.h"
using namespace std;
#define MAX_N 1025
int tree[MAX_N][MAX_N];
int board[MAX_N][MAX_N];
int n, m;

void update(int y, int x, int value) {
	while (x <= n) {
		tree[y][x] += value;
		x += (x & -x);
	}
}

int query(int y, int x) {
	int ret = 0;
	while (x >= 1) {
		ret += tree[y][x];
		x -= (x & -x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int data; cin >> data;
			board[i][j] = data;
			update(i, j, data);
		}
	}
	for (int i = 0; i < m; i++) {
		int cmd; cin >> cmd;
		if (cmd == 0) {
			int y, x, value;	cin >> y >> x >> value;
			update(y, x, value - board[y][x]);
			board[y][x] = value;
		} else {
			int y1, x1, y2, x2;	cin >> y1 >> x1 >> y2 >> x2;
			int ans = 0;
			for (int j = y1; j < y2 + 1; j++)
				ans += query(j, x2) - query(j,x1-1);
			cout << ans << '\n';
		}
	}
}