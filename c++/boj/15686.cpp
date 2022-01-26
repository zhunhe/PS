/*
 * 치킨 배달
 * https://www.acmicpc.net/problem/15686
 */

#include "bits/stdc++.h"
using namespace std;

#define HOME	1
#define KFC		2

struct coor {
	int y, x;
};

int n, m, ans = 1e9;
vector<vector<int>> board;
vector<coor> home;
vector<coor> kfc;
vector<coor> tmp;

void dfs(int depth, int start) {
	if (depth == m) {
		int allDist = 0;
		for (coor h : home) {
			int houseDist = 1e9;
			for (coor k : tmp)
				houseDist = min(houseDist, abs(k.y - h.y) + abs(k.x - h.x));
			allDist += houseDist;
		}
		ans = min(ans, allDist);
		return;
	}
	for (int i = start; i < kfc.size(); i++) {
		tmp.push_back(kfc[i]);
		dfs(depth + 1, i + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	board.resize(n, vector<int>(n));
	for (vector<int> &v : board) for (int &elem : v) cin >> elem;
	for (int i = 0; i < n * n; i++) {
		if (board[i/n][i%n] == KFC)
			kfc.push_back({i/n, i%n});
		else if (board[i/n][i%n] == HOME)
			home.push_back({i/n, i%n});
	}
	dfs(0, 0);
	cout << ans;
}