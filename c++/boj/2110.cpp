/*
 * 공유기 설치
 * https://www.acmicpc.net/problem/2110
 */

#include <bits/stdc++.h>

int main() {
	int n, c;	std::cin >> n >> c;
	std::vector<int> house(n);
	for (int i = 0; i < n; i++) std::cin >> house[i];
	sort(house.begin(), house.end());
	int ans = 0, left = 1, right = house.back() - house.front();
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int point = house[0];
		for (int i = 0; i < n; i++) {
			if (house[i] - point < mid) continue;
			cnt++;
			point = house[i];
		}
		if (cnt >= c) {
			ans = std::max(ans, mid);
			left = mid + 1;
		} else right = mid - 1;
	}
	std::cout << ans;
}