/*
 * 괄호
 * https://www.acmicpc.net/problem/5582
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
	std::string s1;	std::cin >> s1;	s1 = " " + s1;
	std::string s2;	std::cin >> s2;	s2 = " " + s2;
	int max = 0;
	std::vector<std::vector<int> > dp(s1.length(), std::vector<int>(s2.length()));
	for (int i = 1; i < s1.length(); i++)
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] != s2[j]) continue;
			dp[i][j] = dp[i - 1][j - 1] + 1;
			max = std::max(max, dp[i][j]);
		}
    std::cout << max;
}