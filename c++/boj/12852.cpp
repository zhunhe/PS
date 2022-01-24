/*
 * 1로 만들기 2
 * https://www.acmicpc.net/problem/12852
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> dp(n + 1);
	vector<int> pre(n + 1);
	for (int i = 2; i < n + 1; i++) {
		dp[i] = dp[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			pre[i] = i / 3;
		}
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			pre[i] = i / 2;
		}
	}
	cout << dp[n] << '\n';
	while (n) {
		cout << n << ' ';
		n = pre[n];
	}
}