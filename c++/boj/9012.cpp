/*
 * 괄호
 * https://www.acmicpc.net/problem/9012
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		string s;	cin >> s;
		int cnt = 0;	bool vps = true;
		for (auto c : s) {
			if (c == '(') cnt++;
			else cnt--;
			if (cnt < 0) {
				vps = false;
				break;
			}
		}
		cout << (vps && cnt == 0 ? "YES\n" : "NO\n");
    }
}
