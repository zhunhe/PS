/*
 * 계단 오르기
 * https://www.acmicpc.net/problem/2579
 */

#include <bits/stdc++.h>

int main() {
	int n;	std::cin >> n;
	std::vector<int> stair(n);
	for (int i = 0; i < n; i++) std::cin >> stair[i];
	std::vector<int> dp(n, 1);
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = std::max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i = 3; i < n; i++) dp[i] = std::max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
    std::cout << dp[n - 1];
}