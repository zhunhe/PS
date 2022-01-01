/*
 * 속타는 저녁 메뉴
 * https://www.acmicpc.net/problem/11585
 */

#include <bits/stdc++.h>
using namespace std;
int n;

vector<int> getPI(string s) {
	vector<int> PI(s.length());
	int j = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j && s[i] != s[j]) j = PI[j - 1];
		if (s[i] == s[j]) PI[i] = ++j;
	}
	return PI;
}

int gcd(int v1, int v2) {
	if (v2 == 0) return v1;
	else return gcd(v2, v1%v2);
}

void KMP(string dst, string src) {
	vector<int> PI = getPI(src);
	vector<int> ans;
	int j = 0;
	int cnt = 0;
	for (int i = 0; i < dst.size(); i++) {
		while (j && dst[i] != src[j]) j = PI[j - 1];
		if (dst[i] == src[j]) {
			if (j == n - 1) {
				if (i - n + 1 < n)
					cnt++;
				j = PI[j];
			} else j++;
		}
	}
	int gcd_ret = gcd(n, cnt);
	cout << cnt/gcd_ret << '/' << n/gcd_ret;
}

int main() {
	cin >> n;
	string s1 = "", s2 = "";
	for (int i = 0; i < n; i++)	{
		string tmp; cin >> tmp;
		s1 += tmp;
	}
	s1 += s1;
	for (int i = 0; i < n; i++) {
		string tmp;	cin >> tmp;
		s2 += tmp;
	}
	KMP(s1, s2);
}