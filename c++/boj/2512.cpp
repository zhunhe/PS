/*
 * 예산
 * https://www.acmicpc.net/problem/2512
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <vector>

int sum_of_budget(std::vector<int> budget, int mid) {
	int ans = 0;
	for (int i = 0; i < budget.size(); i++) {
		if (budget[i] < mid) ans += budget[i];
		else ans += mid;
	}
	return ans;
}

int main() {
	FAST_IO();
	int n;	std::cin >> n;
	std::vector<int> budget(n);
	for (int i = 0; i < n; i++)	std::cin >> budget[i];
	int m;	std::cin >> m;
	int left = 1;	int right = m;
	int ans = left;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (sum_of_budget(budget, mid) > m) right = mid - 1;
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	int max = *max_element(budget.begin(), budget.end());
	if (ans > max) std::cout << max;
	else std::cout << ans;
}