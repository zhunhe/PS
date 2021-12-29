/*
 * LCS 2
 * https://www.acmicpc.net/problem/9252
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1;	cin >> s1;	s1 = " " + s1;
	string s2;	cin >> s2;	s2 = " " + s2;
	vector<vector<string> > dp(s1.length(), vector<string>(s2.length()));
	for (int i = 1; i < s1.length(); i++) {
		for (int j = 1; j < s2.length(); j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + s1[i];
			else if (dp[i][j - 1].length() >= dp[i - 1][j].length())
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[s1.length() - 1][s2.length() - 1].length() << '\n';
	cout << dp[s1.length() - 1][s2.length() - 1];
}