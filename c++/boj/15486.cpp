/*
 * 퇴사 2
 * https://www.acmicpc.net/problem/15486
 */

#include "bits/stdc++.h"
using namespace std;
#define MAXN	1500001
int period[MAXN], profit[MAXN], dp[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> period[i] >> profit[i];
	for (int i = 0; i < n; i++) {
		if (i + period[i] > n) continue;
		dp[i] = profit[i];
		for (int j = 1; j <= 60 && i - j >= 0; j++)
			if (period[i - j] + (i - j) <= i)
				dp[i] = max(dp[i], dp[i - j] + profit[i]);
	}
	cout << *max_element(dp, dp + n);
}