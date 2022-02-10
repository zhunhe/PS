/*
 * 이친수
 * https://www.acmicpc.net/problem/2193
 */

#include "bits/stdc++.h"
using namespace std;
long long dp[91];

int main() {
	int n;	cin >> n;
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i < n + 1; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	cout << dp[n];
}