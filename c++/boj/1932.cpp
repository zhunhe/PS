/*
 * 정수 삼각형
 * https://www.acmicpc.net/problem/1932
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> dp[i][j];
			if (i == 0) break;
			if (j == 0)
				dp[i][j] += dp[i-1][j];
			else if (j == i)
				dp[i][j] += dp[i-1][j-1];
			else
				dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[n-1][i]);
	cout << ans;
}