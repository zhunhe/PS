/*
 * 과자 나눠주기
 * https://www.acmicpc.net/problem/16401
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <vector>
typedef long long	ll;

int main() {
	FAST_IO();
	int m, n;	std::cin >> m >> n;
	std::vector<int> snack(n);
	for (int i = 0; i < n; i++) std::cin >> snack[i];
	ll left = 1;	ll right = 1e9;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += snack[i] / mid;
		}
		if (cnt >= m) {
			left = mid + 1;
			ans = mid;
		} else right = mid - 1;
	}
	std::cout << ans;
}