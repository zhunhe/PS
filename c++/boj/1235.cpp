/*
 * 학생 번호
 * https://www.acmicpc.net/problem/1235
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<string> s(n);
	for (string &elem : s) cin >> elem;
	const int len = s[0].size();
	for (int i = 1; i < len + 1; i++) {
		set<string> count;
		int j;
		for (j = 0; j < s.size(); j++) {
			string tmp = s[j].substr(len - i, len);
			count.insert(tmp);
			if (count.size() != j + 1)
				break;
		}
		if (j != s.size()) continue;
		cout << i;
		return 0;
	}
}