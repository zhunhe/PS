/*
 * 단어의 개수
 * https://www.acmicpc.net/problem/1152
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;	getline(cin, s);
	int i = 0, ans = 0;
	while (i < s.size()) {
		while (i < s.size() && s[i] == ' ')
			i++;
		if (i < s.size() && s[i] != ' ')
			ans++;
		while (i < s.size() && s[i] != ' ')
			i++;
	}
	cout << ans;
}