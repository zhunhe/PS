/*
 * 병사 배치하기
 * https://www.acmicpc.net/problem/18353
 */

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;	std::cin >> n;
	std::vector<int> str(n);
	for (int i = 0; i < n; i++) std::cin >> str[i];
	std::vector<int> dp(n, 1);
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (str[j] <= str[i]) continue;
			dp[i] = std::max(dp[i], dp[j] + 1);
		}
	}
    std::cout << n - *std::max_element(dp.begin(), dp.end());
}