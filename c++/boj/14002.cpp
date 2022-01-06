/*
 * 가장 긴 증가하는 부분 수열 4
 * https://www.acmicpc.net/problem/14002
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> LIS(n);
	for (int &elem : LIS) cin >> elem;
	vector<int> dp(n, 1);
	vector<vector<int>> ans(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (LIS[j] >= LIS[i]) continue;
			if (dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				ans[i] = ans[j];
			}
		}
		ans[i].push_back(LIS[i]);
	}
	int idx = max_element(dp.begin(), dp.end()) - dp.begin();
	cout << dp[idx] << '\n';
	for (auto elem : ans[idx]) cout << elem << ' ';
}