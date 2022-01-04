/*
 * 가장 긴 증가하는 부분 수열
 * https://www.acmicpc.net/problem/11053
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> a(n), dp(n, 1);
	for (auto &elem : a) cin >> elem;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
	cout << *max_element(dp.begin(), dp.end());
}