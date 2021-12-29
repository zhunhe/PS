/*
 * 평범한 배낭
 * https://www.acmicpc.net/problem/12865
 */

#include <bits/stdc++.h>

int main() {
	int n, k;	std::cin >> n >> k;
	std::vector<std::pair<int, int> > v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i].first >> v[i].second;
	std::vector<std::vector<int> > dp(n + 1, std::vector<int>(k + 1));
	for (int i = 1; i <= n; i++) {
		const int weight = v[i - 1].first;
		const int price = v[i - 1].second;
		for (int j = 1; j < weight; j++) dp[i][j] = dp[i - 1][j];
		for (int j = weight; j <= k; j++) dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight] + price);
	}
	std::cout << dp[n][k];
}