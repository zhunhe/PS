/*
 * 비숍
 * https://www.acmicpc.net/problem/1799
 */

#include "bits/stdc++.h"
using namespace std;
vector<vector<int>> board;

int n, cntOdd, cntEven;

bool isValid(int y, int x) {
	for (int k = 1; y - k >= 0 && x - k >= 0; k++)
		if (board[y][x] == board[y - k][x - k]) return false;
	for (int k = 1; y - k >= 0 && x + k < n; k++)
		if (board[y][x] == board[y - k][x + k]) return false;
	return true;
}

int countBishop() {
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 2)
				cnt++;
	return cnt;
}

void dfs(int start, int type) {
	if (type == 0)
		cntEven = max(cntEven, countBishop());
	else
		cntOdd = max(cntOdd, countBishop());
	for (int i = start; i < n * n; i++) {
		if (board[i/n][i%n] != 1) continue;
		if (type == 0 && i/n % 2 != i%n % 2) continue;
		if (type == 1 && i/n % 2 == i%n % 2) continue;
		board[i/n][i%n] = 2;
		if (isValid(i/n, i%n))
			dfs(i + 1, type);
		board[i/n][i%n] = 1;
	}
}

int main() {
	cin >> n;
	board.resize(n, vector<int>(n));
	for (vector<int> &v : board) for (int &elem : v) cin >> elem;
	for (int k = 0; k < 2; k++)
		dfs(k, k);
	cout << cntEven + cntOdd;
}