/*
 * 라면 사기 (Large)
 * https://www.acmicpc.net/problem/18186
 */

#include "bits/stdc++.h"
using namespace std;

int64_t ans;

int main() {
	int n, b, c;	cin >> n >> b >> c;
	vector<int64_t> factory(n), tmp(n);
	for (int64_t &elem : factory) cin >> elem;
	if (b <= c) {
		for (int i = 0; i < n; i++)
			ans += b * factory[i];
	} else {
		ans = b * factory[0];
		for (int i = 1; i < n; i++) {
			int64_t _min = min(factory[i], factory[i - 1]);
			factory[i] -= _min, tmp[i] += _min;
			ans += c * _min;
			_min = min(factory[i], tmp[i - 1]);
			factory[i] -= _min;
			ans += c * _min + b * factory[i];
		}
	}
	cout << ans;
}