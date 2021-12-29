/*
 * 예산
 * https://www.acmicpc.net/problem/2512
 */

#include <bits/stdc++.h>

int main() {
	int n;    std::cin >> n;
	std::vector<int> budget(n);
	for (int i = 0; i < n; i++) std::cin >> budget[i];
	int m;    std::cin >> m;
	int ans, left = 1, right = *std::max_element(budget.begin(), budget.end());
	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += std::min(mid, budget[i]);
		if (sum <= m) {
			ans = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	std::cout << ans;
}