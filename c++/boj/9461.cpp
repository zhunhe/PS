/*
 * 파도반 수열
 * https://www.acmicpc.net/problem/9461
 */

#include "bits/stdc++.h"
using namespace std;
int main() {
	vector<long long> p(101, 1), dp(101);
	p[4] = 2;
	p[5] = 2;
	for (int i = 6; i < 101; i++) {
		dp[i] = p[i - 5];
		p[i] = p[i - 1] + dp[i];
	}
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		cout << p[n] << '\n';
	}
}