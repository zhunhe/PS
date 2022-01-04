/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<int> coin(n), dp(k + 1);
	for (int &elem : coin) cin >> elem;
	dp[0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];
    cout << dp[k];
}