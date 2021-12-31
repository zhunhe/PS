/*
 * LCS 3
 * https://www.acmicpc.net/problem/1958
 */

#include <bits/stdc++.h>
using namespace std;

int dp[102][102][102];

int main() {
	string s1, s2, s3;	cin >> s1 >> s2 >> s3;
	int s1_len = s1.length(), s2_len = s2.length(), s3_len = s3.length();
	s1 = " " + s1; s2 = " " + s2; s3 = " " + s3;
	for (int i = 1; i <= s1_len; i++) {
		for (int j = 1; j <= s2_len; j++) {
			for (int k = 1; k <= s3_len; k++) {
				if (s1[i] == s2[j] && s1[i] == s3[k])
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				else
					dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
			}
		}
	}
	cout << dp[s1_len][s2_len][s3_len];
}