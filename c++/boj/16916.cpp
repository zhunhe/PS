/*
 * 부분 문자열
 * https://www.acmicpc.net/problem/16916
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

int KMP(string dst, string src) {
	vector<int> PI = getPI(src);
	int j = 0;
	for (int i = 0; i < dst.size(); i++) {
		while (j && dst[i] != src[j]) {
			j = PI[j - 1];
		}
		if (dst[i] == src[j]) {
			if (j == src.size() - 1) {
				return i - src.size() + 2;
				j = PI[j];
			} else j++;
		}
	}
	return 0;
}

int main() {
	string s1, s2;	cin >> s1 >> s2;
	if (KMP(s1, s2))
		cout << 1;
	else
		cout << 0;
}