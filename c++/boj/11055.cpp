/*
 * 가장 큰 증가 부분 수열
 * https://www.acmicpc.net/problem/11055
 */

#include "bits/stdc++.h"
using namespace std;
int num[1001];
int dp[1001];

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n; i++) cin >> num[i];
	for (int i = 0; i < n; i++) {
		dp[i] = num[i];
		for (int j = i - 1; j >= 0; j--)
			if (num[i] > num[j])
				dp[i] = max(dp[i], dp[j] + num[i]);
	}
	cout << *max_element(dp, dp + n);
}