/*
 * 나무 자르기
 * https://www.acmicpc.net/problem/2805
 */

#include <iostream>
#include <vector>
#include <algorithm>
typedef long long	ll;

int main() {
	int n, m;	std::cin >> n >> m;
	std::vector<ll> log(n);
	for (int i = 0; i < n; i++) std::cin >> log[i];
	ll left = 1, right = *max_element(log.begin(), log.end());
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cut = 0;
		for (int i = 0; i < n; i++)
			cut += std::max(log[i] - mid, 0LL);
		if (cut >= m) {
			left = mid + 1;
			ans = mid;
		} else	right = mid - 1;
	}
	std::cout << ans;
}