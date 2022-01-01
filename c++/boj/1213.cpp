/*
 * 팰린드롬 만들기
 * https://www.acmicpc.net/problem/1213
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;	cin >> s;
	vector<int> alpha(26);
	for (int i = 0; i < s.size(); i++)
		alpha[s[i] - 'A']++;
	char center = 0;
	for (int i = 0; i < 26; i++) {
		if (alpha[i]%2) {
			if (!center)
				center = i + 'A';
			else {
				cout << "I'm Sorry Hansoo";
				return 0;
			}
		}
	}
	string ans = "";
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < alpha[i]/2; j++)
			ans += i + 'A';
	if (center)
		ans += center;
	for (int i = 25; i >= 0; i--)
		for (int j = 0; j < alpha[i]/2; j++)
			ans += i + 'A';
	cout << ans;
}