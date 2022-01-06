/*
 * 평범한 배낭
 * https://www.acmicpc.net/problem/12865
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<int> dp(k + 1);
	for (int i = 0; i < n; i++) {
		int w, c;	cin >> w >> c;
		for (int j = k; j >= w; j--)
			dp[j] = max(dp[j], dp[j - w] + c);
	}
	cout << dp[k];
}