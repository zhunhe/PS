/*
 * Equidistant Letters
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	cin.ignore();
	while (t--) {
		string s;	cin >> s;
		vector<int> count(26);
		for (int i = 0; i < s.size(); i++)
			count[s[i]-'a']++;
		for (int i = 0; i < 26; i++)
			while (count[i]-- > 0)
				cout << (char)(i + 'a');
		cout << '\n';
	}
}