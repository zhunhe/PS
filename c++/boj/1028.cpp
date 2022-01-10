/*
 * 다이아몬드 광산
 * https://www.acmicpc.net/problem/2018
 */

#include "bits/stdc++.h"
using namespace std;

#define DIAMOND		'1'

int main() {
	int r, c;	cin >> r >> c;
	vector<vector<char>> mine(r, vector<char>(c));
	for (vector<char> &v : mine) for (char &elem : v) cin >> elem;
	vector<vector<int>> ld(r, vector<int>(c)), rd(r, vector<int>(c));
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (mine[i][j] == DIAMOND)
				ld[i][j] = rd[i][j] = 1;
	for (int i = 1; i < r; i++)
		for (int j = 0; j < c - 1; j++)
			if (ld[i][j] != 0)
				ld[i][j] = ld[i - 1][j + 1] + 1;
	for (int i = 1; i < r; i++)
		for (int j = c - 1; j >= 1; j--)
			if (rd[i][j] != 0)
				rd[i][j] = rd[i - 1][j - 1] + 1;
	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (mine[i][j] != DIAMOND) continue;
			ans = max(ans, 1);
			for (int k = 1; j - k >= 0 && j + k < c && i + k * 2 < r; k++) {
				if (ld[i + k][j - k] - ld[i][j] != k) continue;
				if (rd[i + k][j + k] - rd[i][j] != k) continue;
				if (rd[i + k * 2][j] - rd[i + k][j - k] != k) continue;
				if (ld[i + k * 2][j] - ld[i + k][j + k] != k) continue;
				ans = max(ans, ld[i + k][j - k] - ld[i][j] + 1);
			}
		}
	}
	cout << ans;
}