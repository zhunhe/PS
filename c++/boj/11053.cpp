/*
 * 가장 긴 증가하는 부분 수열
 * https://www.acmicpc.net/problem/11053
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;	std::cin >> n;
	std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
	std::vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (a[j] >= a[i]) continue;
            if (dp[j] < dp[i]) continue;
            dp[i] = dp[j] + 1;
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end());
}