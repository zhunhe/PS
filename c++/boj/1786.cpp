/*
 * Ã£±â
 * https://www.acmicpc.net/problem/1786
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> getPI(string s) {
	vector<int> PI(s.length());
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j && s[i] != s[j])
			j = PI[j - 1];
		if (s[i] == s[j])
			PI[i] = ++j;
	}
	return PI;
}

void KMP(string dst, string src) {
	vector<int> PI = getPI(src);
	vector<int> ans;
	int j = 0;
	for (int i = 0; i < dst.size(); i++) {
		while (j && dst[i] != src[j]) {
			j = PI[j - 1];
		}
		if (dst[i] == src[j]) {
			if (j == src.size() - 1) {
				ans.push_back(i - src.size() + 2);
				j = PI[j];
			} else j++;
		}
	}
	cout << ans.size() << '\n';
	for (int elem : ans) cout << elem << ' ';
}

int main() {
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	KMP(s1, s2);
}