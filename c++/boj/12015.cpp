/*
 * 가장 긴 증가하는 부분 수열 2
 * https://www.acmicpc.net/problem/12015
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> LIS;
	for (int i = 0; i < n; i++) {
		int x;	cin >> x;
		if (LIS.empty() || x > LIS.back())
			LIS.push_back(x);
		else {
			auto it = lower_bound(LIS.begin(), LIS.end(), x) - LIS.begin();
			LIS[it] = x;
		}
	}
	cout << LIS.size();
}