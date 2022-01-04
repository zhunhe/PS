/*
 * 자원 캐기
 * https://www.acmicpc.net/problem/14430
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	vector<vector<int>> map(n+1, vector<int>(m+1)),  dp(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
		}
	cout << dp[n][m];
}