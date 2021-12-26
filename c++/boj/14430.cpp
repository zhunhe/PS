/*
 * 자원 캐기
 * https://www.acmicpc.net/problem/14430
 */

#include <iostream>
#include <vector>

int main() {
	int n, m;	std::cin >> n >> m;
	std::vector<std::vector<int> > map(n + 1, std::vector<int>(m + 1, 0));
	std::vector<std::vector<int> > dp(n + 1, std::vector<int>(m + 1, 0));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			std::cin >> map[i][j];
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
		}
	std::cout << dp[n][m];
}