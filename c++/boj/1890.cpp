/*
 * 점프
 * https://www.acmicpc.net/problem/1890
 */

#include <bits/stdc++.h>
using namespace std;

long long board[110][110];
long long dp[110][110];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n * n; i++) cin >> board[i/n][i%n];
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n-1 && j == n-1) break;
			if (!dp[i][j]) continue;
			dp[i + board[i][j]][j] += dp[i][j];
			dp[i][j + board[i][j]] += dp[i][j];
		}
	}
	cout << dp[n - 1][n - 1];
}
