/*
 * OX퀴즈
 * https://www.acmicpc.net/problem/8958
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s; s = " " + s;
		vector<int> dp(s.size());
		for (int i = 1; i < s.size(); i++)
			if (s[i] == 'O') dp[i] += dp[i - 1] + 1;
		cout << accumulate(dp.begin(), dp.end(), 0) << '\n';
	}
}