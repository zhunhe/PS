/*
 * 최소 편집
 * https://www.acmicpc.net/problem/15483
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1;	cin >> s1;	s1 = " " + s1; int s1_len = s1.size();
	string s2;	cin >> s2;	s2 = " " + s2; int s2_len = s2.size();
	vector<vector<int>> dp(s1_len, vector<int>(s2_len));
	for (int i = 1; i < s1_len; i++) dp[i][0] = i;
	for (int i = 1; i < s2_len; i++) dp[0][i] = i;
	for (int i = 1; i < s1_len; i++) {
		for (int j = 1; j < s2_len; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = min({dp[i-1][j-1], dp[i][j-1], dp[i-1][j]}) + 1;
		}
	}
	cout << dp[s1_len-1][s2_len-1];
}