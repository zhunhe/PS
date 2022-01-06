/*
 * 가장 긴 증가하는 부분 수열 3
 * https://www.acmicpc.net/problem/12738
 */

#include "bits/stdc++.h"
using namespace std;

#define LOWER_BOUND_IDX(s, x)	lower_bound(s.begin(), s.end(), x) - s.begin()

int main() {
	int n;	cin >> n;
	vector<int> dp;
	for (int i = 0; i < n; i++) {
		int x;	cin >> x;
		if (dp.empty() || x > dp.back())
			dp.push_back(x);
		else
			dp[LOWER_BOUND_IDX(dp, x)] = x;
	}
	cout << dp.size() << '\n';
}