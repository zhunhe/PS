/*
 * 2048(Easy)
 * https://www.acmicpc.net/problem/12100
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n;
ll ANSWER;

vector<vector<ll>> up(vector<vector<ll>> org) {
	vector<vector<ll>> board = org;
	for (int j = 0; j < n; j++) {
		int start = 0;
		for (int end = 0; end < n; end++) {
			if (board[start][j] == 0 && start < end) start++;
			if (board[end][j] == 0) continue;
			if (start < end && board[start][j] == board[end][j]) {
				board[start][j] *= 2;
				board[end][j] = 0;
				start = end + 1;
			} else if (board[end][j] != 0) start = end;
		}
		for (int i = 0; i < n; i++) {
			if (board[i][j] != 0) continue;
			for (int k = i + 1; k < n; k++) {
				if (board[k][j] == 0) continue;
				board[i][j] = board[k][j];
				board[k][j] = 0;
				break;
			}
		}
	}
	return board;
}

vector<vector<ll>> down(vector<vector<ll>> org) {
	vector<vector<ll>> board = org;
	for (int j = 0; j < n; j++) {
		int start = n - 1;
		for (int end = n - 1; end >= 0; end--) {
			if (board[start][j] == 0 && start > end) start--;
			if (board[end][j] == 0) continue;
			if (start > end && board[start][j] == board[end][j]) {
				board[start][j] *= 2;
				board[end][j] = 0;
				start = end - 1;
			} else if (board[end][j] != 0) start = end;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (board[i][j] != 0) continue;
			for (int k = i - 1; k >= 0; k--) {
				if (board[k][j] == 0) continue;
				board[i][j] = board[k][j];
				board[k][j] = 0;
				break;
			}
		}
	}
	return board;
}

vector<vector<ll>> left(vector<vector<ll>> org) {
	vector<vector<ll>> board = org;
	for (int i = 0; i < n; i++) {
		int start = 0;
		for (int end = 0; end < n; end++) {
			if (board[i][start] == 0 && start < end) start++;
			if (board[i][end] == 0) continue;
			if (start < end && board[i][start] == board[i][end]) {
				board[i][start] *= 2;
				board[i][end] = 0;
				start = end + 1;
			} else if (board[i][end] != 0) start = end;
		}
		for (int j = 0; j < n; j++) {
			if (board[i][j] != 0) continue;
			for (int k = j + 1; k < n; k++) {
				if (board[i][k] == 0) continue;
				board[i][j] = board[i][k];
				board[i][k] = 0;
				break;
			}
		}
	}
	return board;
}

vector<vector<ll>> right(vector<vector<ll>> org) {
	vector<vector<ll>> board = org;
	for (int i = 0; i < n; i++) {
		int start = n - 1;
		for (int end = n - 1; end >= 0; end--) {
			if (board[i][start] == 0 && start > end) start--;
			if (board[i][end] == 0) continue;
			if (start > end && board[i][start] == board[i][end]) {
				board[i][start] *= 2;
				board[i][end] = 0;
				start = end - 1;
			} else if (board[i][end] != 0) start = end;
		}
		for (int j = n - 1; j >= 0; j--) {
			if (board[i][j] != 0) continue;
			for (int k = j - 1; k >= 0; k--) {
				if (board[i][k] == 0) continue;
				board[i][j] = board[i][k];
				board[i][k] = 0;
				break;
			}
		}
	}
	return board;
}

void DFS(int L, vector<vector<ll>> board) {
	if (L == 5) {
		for (int i = 0; i < n * n; i++)
			ANSWER = max(ANSWER, board[i / n][i % n]);
		return;
	}
	DFS(L + 1, up(board));
	DFS(L + 1, down(board));
	DFS(L + 1, left(board));
	DFS(L + 1, right(board));
}

int main() {
	cin >> n;
	vector<vector<ll>> board(n, vector<ll>(n));
	for (int i = 0; i < n * n; i++) cin >> board[i / n][i % n];
	DFS(0, board);
	cout << ANSWER << '\n';
}