/*
 * 가장 긴 증가하는 부분 수열 3
 * https://www.acmicpc.net/problem/12738
 */

#include "bits/stdc++.h"
using namespace std;

#define LOWER_BOUND_IDX(s, x)	lower_bound(s.begin(), s.end(), x) - s.begin()

int main() {
	int n;	cin >> n;
	vector<int> LIS(n), dp;
	for (int &elem : LIS) cin >> elem;
	for (int x : LIS) {
		if (dp.empty() || x > dp.back())
			dp.push_back(x);
		else
			dp[LOWER_BOUND_IDX(dp, x)] = x;
	}
	cout << dp.size() << '\n';
}