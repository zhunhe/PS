/*
 * 랜선자르기
 * https://www.acmicpc.net/problem/1654
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	FAST_IO();
	int k, n; std::cin >> k >> n;
	std::vector<int> line(k);
	for (int i = 0; i < k; i++)	std::cin >> line[i];
	long left = 1;	long right = *max_element(line.begin(), line.end());
	long ans = 0;
	while (left <= right) {
		long mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 0; i < k; i++)
			cnt += line[i] / mid;
		if (cnt >= n) {
			ans = mid;
			left = mid + 1;
		} else
			right = mid - 1;
	}
	std::cout << ans;
	return 0;
}