/*
 * 공통 부분 문자열
 * https://www.acmicpc.net/problem/5582
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1;	cin >> s1;	s1 = " " + s1;
	string s2;	cin >> s2;	s2 = " " + s2;
	int ans = 0;
	vector<vector<int> > dp(s1.length(), vector<int>(s2.length()));
	for (int i = 1; i < s1.length(); i++)
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] != s2[j]) continue;
			dp[i][j] = dp[i - 1][j - 1] + 1;
			ans = max(ans, dp[i][j]);
		}
    cout << ans;
}