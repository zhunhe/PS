/*
 * 봄버맨
 * https://www.acmicpc.net/problem/16918
 */

#include "bits/stdc++.h"
using namespace std;

#define EMPTY		'.'
#define BOMB		'O'

int main() {
	int r, c, n;	cin >> r >> c >> n;
	vector<vector<char>> board(r + 2, vector<char>(c + 2));
	vector<vector<int>> time(r + 2, vector<int>(c + 2));
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++) {
			cin >> board[i][j];
			if (board[i][j] == BOMB)
				time[i][j] = 3; // 3s 뒤 터짐
		}
	for (int t = 2; t <= n; t++) {
		if (t % 2) {	// 폭발
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					if (time[i][j] == t) {
						time[i][j] = 0;
						board[i][j] = EMPTY;
						board[i-1][j] = EMPTY;
						board[i][j+1] = EMPTY;
						board[i+1][j] = EMPTY;
						board[i][j-1] = EMPTY;
					}
				}
			}
		} else {	// 설치
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					if (board[i][j] == EMPTY) {
						board[i][j] = BOMB;
						time[i][j] = t + 3;
					}
				}
			}
		}
	}
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cout << board[i][j] << (j == c ? "\n" : "");
}

