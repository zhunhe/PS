/*
 * 알파벳 찾기
 * https://www.acmicpc.net/problem/10809
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;	cin >> s;
	vector<int> ans(26, -1);
	for (int i = 0; i < s.size(); i++)
		if (ans[s[i] - 'a'] == -1)
			ans[s[i] - 'a'] = i;
	for (int elem : ans) cout << elem << ' ';
}