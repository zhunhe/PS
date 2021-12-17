/*
 * ¼­¹ö½Ç
 * https://www.acmicpc.net/problem/17245
 */

#include <iostream>
#include <algorithm>
#include <vector>
typedef unsigned long long	ull;

int main() {
	int n;	std::cin >> n;
	std::vector<ull> server(n * n);
	ull max = 0;
	for (int i = 0; i < n * n; i++)	std::cin >> server[i];
	for (int i = 0; i < n * n; i++) max += server[i];
	ull ans = 0, left = 1, right = *std::max_element(server.begin(), server.end());
	while (left <= right) {
		ull mid = (left + right) / 2;
		ull cnt = 0;
		for (int i = 0; i < n * n; i++)
			cnt += std::min(mid, server[i]);
		if ((double)cnt/max >= 0.5) {
			ans = mid;
			right = mid - 1;
		} else left = mid + 1;
	}
	std::cout << ans;
}