/*
 * 계단 오르기
 * https://www.acmicpc.net/problem/2579
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> stair(n), dp(n, 1);
	for (int &elem : stair) cin >> elem;
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
    for (int i = 3; i < n; i++) dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
    cout << dp[n - 1];
}