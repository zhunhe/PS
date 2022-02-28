/*
 * 동전
 * https://www.acmicpc.net/problem/9084
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> coins(n);
		for (int &elem : coins) cin >> elem;
		int m;	cin >> m;
		vector<int> dp(m + 1);
		dp[0] = 1;
		for (int coin : coins)
			for (int i = coin; i < m + 1; i++)
				dp[i] += dp[i - coin];
		cout << dp[m] << '\n';
	}
}