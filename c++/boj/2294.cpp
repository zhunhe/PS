/*
 * µ¿Àü 2
 * https://www.acmicpc.net/problem/2294
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<int> coin(n);
	for (int &elem : coin) cin >> elem;
	vector<int> dp(k + 1, 1e9);
	dp[0] = 0;
	for (int value : coin)
		for (int j = value; j <= k; j++)
			dp[j] = min(dp[j], dp[j - value] + 1);
	if (dp[k] == 1e9) cout << -1;
	else cout << dp[k];
};