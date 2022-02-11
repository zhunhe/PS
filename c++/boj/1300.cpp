/*
 * K번째 수
 * https://www.acmicpc.net/problem/1300
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	int left = 1, right = k, ans;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i < n + 1; i++)
			cnt += min(mid / i, n);
		if (cnt < k)
			left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans;
}