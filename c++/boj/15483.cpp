/*
 * 최소 편집
 * https://www.acmicpc.net/problem/15483
 */

#include <bits/stdc++.h>
using namespace std;
int dp[1002][1002];

int main() {
	string s1;	cin >> s1;	s1 = " " + s1;
	string s2;	cin >> s2;	s2 = " " + s2;
	for (int i = 1; i <= s1.length(); i++) dp[i][0] = i;
	for (int i = 1; i <= s2.length(); i++) dp[0][i] = i;
	for (int i = 1; i <= s1.length(); i++) {
		for (int j = 1; j <= s2.length(); j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
		}
	}
	cout << dp[s1.length()][s2.length()];
}