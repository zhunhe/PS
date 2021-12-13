/*
 * 풍선 공장
 * https://www.acmicpc.net/problem/15810
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
typedef long long	ll;

ll sum(std::vector<int> staff, ll mid) {
	ll sum = 0;
	for (int i = 0; i < staff.size(); i++)
		sum += mid / staff[i];
	return sum;
}

int main() {
	FAST_IO();
	int n, m;	std::cin >> n >> m;
	std::vector<int> staff(n);
	for (int i = 0; i < n; i++) std::cin >> staff[i];
	ll min = *std::min_element(staff.begin(), staff.end());
	ll left = 0;	ll right = min * m;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (sum(staff, mid) >= m) {
			ans = mid;
			right = mid - 1;
		} else left = mid + 1;
	}
	std::cout << ans;
}