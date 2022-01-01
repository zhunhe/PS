/*
 * 전화번호 목록
 * https://www.acmicpc.net/problem/5052
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<string> s(n);
		for (string &elem : s) cin >> elem;
		sort(s.begin(), s.end());
		bool find = false;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1].substr(0, s[i].length())) {
				find = true;
				break;
			}
		}
		cout << (find ? "NO\n" : "YES\n");
	}
}
