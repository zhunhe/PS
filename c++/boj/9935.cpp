/*
 * 문자열 폭발
 * https://www.acmicpc.net/problem/9935
 */

#define FAST_IO()	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;	cin >> s1 >> s2;
	vector<char> ans;
	int s2_len = s2.length();
	for (auto c : s1) {
		ans.push_back(c);
		if (ans.size() < s2_len) continue;
		bool flag = true;
		for (int i = 0; i < s2_len; i++) {
			if (ans[ans.size() - 1 - i] != s2[s2_len - 1 - i]) {
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		for (int i = 0; i < s2_len; i++) ans.pop_back();
	}
	if (ans.empty()) cout << "FRULA";
	else for (auto c : ans) cout << c;
}
