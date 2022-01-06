/*
 * 가장 긴 증가하는 부분 수열 5
 * https://www.acmicpc.net/problem/14003
 */

#include "bits/stdc++.h"
using namespace std;

int main(void)
{
	int n;	cin >> n;
	vector<int> LIS(n), idx(n), dp;
	for (int &elem : LIS) cin >> elem;
	dp.push_back(LIS[0]);
	for (int i = 1; i < n; i++) {
		const int x = LIS[i];
		if (x > dp.back()) {
			dp.push_back(x);
			idx[i] = dp.size() - 1;
		}
		else {
			int find = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
			dp[find] = x;
			idx[i] = find;
		}
	}
	vector<int> ans;
	int len = dp.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (idx[i] != len) continue;
		ans.push_back(LIS[i]);
		len--;
	}
	reverse(ans.begin(), ans.end());
	cout << dp.size() << '\n';
	for (int elem : ans) cout << elem << ' ';
}