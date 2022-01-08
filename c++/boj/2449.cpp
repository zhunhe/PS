/*
 * 전구
 * https://www.acmicpc.net/problem/2449
 */

#include "bits/stdc++.h"
using namespace std;

vector<int> bulb;
int n, k, cache[200][200];

int dp(int left, int right) {
	if (left >= right) return 0;
	int &ret = cache[left][right];
	if (ret) return ret;
	ret = 1e9;
	for (int i = left; i < right; i++) {
		int p = (bulb[left] == bulb[i + 1] ? 0 : 1);
		ret = min(ret, dp(left, i) + dp(i + 1, right) + p);
	}
	return ret;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int tmp;	cin >> tmp;
		if (bulb.empty() || bulb.back() != tmp)
			bulb.push_back(tmp);
	}
	cout << dp(0, bulb.size() - 1);
}