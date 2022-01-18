/*
 * N-Queen
 * https://www.acmicpc.net/problem/9663
 */

#include "bits/stdc++.h"
using namespace std;
int n, ans;
vector<int> board;

bool isValid(int depth) {
	for (int i = 0; i < depth; i++) {
		if (board[depth] == board[i]) return false;
		if (depth - i == abs(board[depth] - board[i])) return false;
	}
	return true;
}

void dfs(int depth) {
	if (depth == n) {
		ans++;
		return;
	}
	for (int i = 0; i < n; i++) {
		board[depth] = i;
		if (isValid(depth)) {
			dfs(depth + 1);
		}
	}
}

int main() {
	cin >> n;
	board.resize(n);
	dfs(0);
	cout << ans;
}