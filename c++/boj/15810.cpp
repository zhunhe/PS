/*
 * 풍선 공장
 * https://www.acmicpc.net/problem/15810
 */

#include <bits/stdc++.h>
typedef long long    ll;

int main() {
	int n, m;    std::cin >> n >> m;
	std::vector<int> time(n);
	for (int i = 0; i < n; i++) std::cin>> time[i];
	ll ans, left = 1, right = (ll)*std::min_element(time.begin(), time.end()) * m;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += mid / time[i];
		if (cnt >= m) {
			ans = mid;
			right = mid - 1;
		} else left = mid + 1;
	}
	std::cout << ans;
}