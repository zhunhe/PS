/*
 * ����� �賶 2
 * https://www.acmicpc.net/problem/12920
 */

#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, m;	cin >> n >> m;
	vector<int> dp(m + 1);
	for (int i = 0; i < n; i++) {
		int v, c, k;	cin >> v >> c >> k;
		int t = 1;
		int temp;
		while (k > 0) {
			temp = min(k, t);
			for (int j = m; j >= v * temp; j--)
				dp[j] = max(dp[j - v * temp] + c * temp, dp[j]);
			t *= 2;
			k -= temp;
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}