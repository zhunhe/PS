/*
 * 접미사 배열
 * https://www.acmicpc.net/problem/11656
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;	cin >> s;
	vector<string> ans;
	for (int i = 0; i < s.size(); i++)
		ans.push_back(s.substr(s.size() - i - 1, s.size()));
	sort(ans.begin(), ans.end());
	for (string elem : ans) cout << elem << '\n';
}