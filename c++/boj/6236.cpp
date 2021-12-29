/*
 * 용돈 관리
 * https://www.acmicpc.net/problem/6236
 */

#include <bits/stdc++.h>

bool func(int mid, int n, int m, std::vector<int> money) {
	int num = 1;
	int sum = mid;
	for (int i = 0; i < n; i++) {
		if (mid < money[i])
			return false;
		if (sum - money[i] < 0) {
			sum = mid;
			num++;
		}
		sum -= money[i];
	}
	return m >= num;
}

int main() {
	int n, m;	std::cin >> n >> m;
	std::vector<int> money(n);
	for (auto &elem : money) std::cin >> elem;
	int ans = 0, left = 1, right = 1e9;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (func(mid, n, m, money)) {
			ans = mid;
			right = mid - 1;
		} else left = mid + 1;
	}
	std::cout << ans;
}