/*
 * 동전 2
 * https://www.acmicpc.net/problem/2294
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<int> coin(n), dp(k + 1, 1e9);
	for (int &elem : coin) cin >> elem;
	dp[0] = 0;
	for (int value : coin)
		for (int j = value; j <= k; j++)
			dp[j] = min(dp[j], dp[j - value] + 1);
	if (dp[k] == 1e9) cout << -1;
	else cout << dp[k];
}