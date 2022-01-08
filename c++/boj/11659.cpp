/*
 * 구간 합 구하기 4
 * https://www.acmicpc.net/problem/11659
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++) cin >> dp[i];
	for (int i = 2; i <= n; i++) dp[i] += dp[i-1];
	vector<pair<int, int>> q(m);
	for (auto &elem : q)
		cin >> elem.first >> elem.second;
	for (auto elem : q)
		cout << dp[elem.second] - dp[elem.first-1] << '\n';
}