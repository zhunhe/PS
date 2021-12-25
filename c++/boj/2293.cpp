/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#include <iostream>
#include <vector>

int main() {
	int n, k;	std::cin >> n >> k;
	std::vector<int> coin(n);
	for (int i = 0; i < n; i++)	std::cin >> coin[i];
	std::vector<int> dp(k + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
    std::cout << dp[k];
}