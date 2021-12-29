/*
 * 상자넣기
 * https://www.acmicpc.net/problem/1965
 */

#include <bits/stdc++.h>

int main() {
	int n;	std::cin >> n;
	std::vector<int> box(n);
	for (int i = 0; i < n; i++) std::cin >> box[i];
	std::vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (box[j] >= box[i]) continue;
			dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
	std::cout << *std::max_element(dp.begin(), dp.end());
}