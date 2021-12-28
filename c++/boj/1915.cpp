/*
 * 가장 큰 정사각형
 * https://www.acmicpc.net/problem/1915
 */

#include <iostream>
#include <algorithm>
using namespace std;

char board[1002][1002];
int dp[1002][1002];

int main() {
	int n, m;	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '0') continue;
			dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans * ans;
}