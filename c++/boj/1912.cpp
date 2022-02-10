/*
 * 연속합
 * https://www.acmicpc.net/problem/1912
 */

#include "bits/stdc++.h"
using namespace std;
int num[100001];
int dp[100001];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	dp[0] = num[0];
	for (int i = 1; i < n; i++) {
		dp[i] = num[i];
		if (dp[i - 1] > 0)
			dp[i] += dp[i - 1];
	}
	cout << *max_element(dp, dp + n);
}