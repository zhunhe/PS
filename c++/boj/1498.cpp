/*
 * �ֱ⹮
 * https://www.acmicpc.net/problem/1498
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

int main() {
	string s;	cin >> s;
	vector<int> PI = getPI(s);
	for (int i = 0; i < s.size(); i++) {
		int len = i + 1 - PI[i];
		if (PI[i] && (i + 1) % len == 0)
			cout << i + 1 << ' ' << (i + 1)/len << '\n';
	}
}