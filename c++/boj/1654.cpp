/*
 * 랜선자르기
 * https://www.acmicpc.net/problem/1654
 */

#include <iostream>
#include <algorithm>
#include <vector>
typedef long long    ll

int main() {
	int k, n; std::cin >> k >> n;
	std::vector<int> line(k);
	for (int i = 0; i < k; i++) std::cin >> line[i];
	ll left = 1; ll right = *max_element(line.begin(), line.end());
	ll ans = 1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;
		if (cnt >= n) {
			ans = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	std::cout << ans;
}