/*
 * 평범한 배낭
 * https://www.acmicpc.net/problem/12865
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<pair<int, int>> v(n + 1);
	for (int i = 1; i <=n; i++) cin >> v[i].first >> v[i].second;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int i = 1; i <= n; i++) {
		const int weight = v[i].first;
		const int price = v[i].second;
		for (int j = 1; j <= k; j++) {
			if (j < weight) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + price);
		}
	}
	cout << dp[n][k];
}