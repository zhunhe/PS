/*
 * 구간 합 구하기 5
 * https://www.acmicpc.net/problem/11660
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;	cin >> n >> m;
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[i][j];
			dp[i][j] += dp[i][j - 1];
		}
	}
	while (m--) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		int ans = 0;
		for (int i = y1; i < y2 + 1; i++)
			ans += dp[i][x2] - dp[i][x1 - 1];
		cout << ans << '\n';
	}
}
