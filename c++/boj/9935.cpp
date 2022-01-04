/*
 * 문자열 폭발
 * https://www.acmicpc.net/problem/9935
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string s1, s2, ans;	cin >> s1 >> s2;
	for (char c : s1) {
		ans += c;
		if (ans.size() < s2.size()) continue;
		if (ans.substr(ans.size() - s2.size(), s2.size()) == s2) {
			ans.erase(ans.size() - s2.size(), s2.size());
		}
	}
	cout << (ans.size() ? ans : "FRULA");
}