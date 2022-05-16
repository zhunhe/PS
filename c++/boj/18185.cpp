/*
 * 라면 사기 (Small)
 * https://www.acmicpc.net/problem/18185
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> factory(n), tmp(n);
	for (int &elem : factory) cin >> elem;
	int ans = 3 * factory[0];
	for (int i = 1; i < n; i++) {
		int _min = min(factory[i], factory[i - 1]);
		factory[i] -= _min, tmp[i] += _min;
		ans += 2 * _min;
		_min = min(factory[i], tmp[i - 1]);
		factory[i] -= _min;
		ans += 2 * _min + 3 * factory[i];
	}
	cout << ans;
}