/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	FAST_IO();
	int n, k;	cin >> n >> k;
	vector<int> coin(n);
	for (int i = 0; i < n; i++)	cin >> coin[i];
	vector<int> dp(k + 1);
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
    cout << dp[k];
}