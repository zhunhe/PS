/*
 * 과자 나눠주기
 * https://www.acmicpc.net/problem/16401
 */

#include <bits/stdc++.h>

int main() {
	int m, n;	std::cin >> m >> n;
	std::vector<int> snack(n);
	for (auto &elem : snack) std::cin >> elem;
	int ans = 0, left = 1, right = *std::max_element(snack.begin(), snack.end());
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 0;
		for (auto elem : snack)
			cnt += elem / mid;
		if (cnt >= m) {
			ans = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	std::cout << ans;
}