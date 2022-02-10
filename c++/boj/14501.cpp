/*
 * 퇴사
 * https://www.acmicpc.net/problem/14501
 */

#include "bits/stdc++.h"
using namespace std;
struct cData {
	int period, profit;
};

int main() {
	int n;	cin >> n;
	vector<cData> consult(n);
	vector<int> dp(n);
	for (cData &elem : consult) cin >> elem.period >> elem.profit;
	for (int now = 0; now < n; now++) {
		if (now + consult[now].period <= n)
			dp[now] = consult[now].profit;
		for (int past = now - 1; past >= 0; past--) {
			if (past + consult[past].period - 1 >= now) continue;
			if (dp[past] + consult[now].profit < dp[now]) continue;
			if (now + consult[now].period > n) continue;
			dp[now] = dp[past] + consult[now].profit;
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}