/*
 * 2×n 타일링 2
 * https://www.acmicpc.net/problem/11727
 */

#include "bits/stdc++.h"
using namespace std;
#define MOD	10007
int dp[1001];

int main() {
	int n;	cin >> n;
	dp[1] = 1;
	for (int i = 2; i < n + 1; i++)
		dp[i] = (dp[i - 1] * 2 + (i & 1 ? -1 : 1)) % MOD;
	cout << dp[n];
}