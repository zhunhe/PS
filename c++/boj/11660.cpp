/*
 * 구간 합 구하기 5
 * https://www.acmicpc.net/problem/11660
 */

#include "bits/stdc++.h"
using namespace std;

#define Y1		0
#define X1		1
#define Y2		2
#define X2		3

struct coor{
	int y1, x1, y2, x2;
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;	cin >> n >> m;
	vector<vector<int>> dp(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> dp[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			dp[i][j] += dp[i][j-1];
	vector<coor> q(m);
	for (auto &v : q) cin >> v.y1 >> v.x1 >> v.y2 >> v.x2;
	for (auto v : q) {
		int ans = 0;
		for (int j = v.y1; j <= v.y2; j++)
			ans += dp[j][v.x2] - dp[j][v.x1 - 1];
		cout << ans << '\n';
	}
}
