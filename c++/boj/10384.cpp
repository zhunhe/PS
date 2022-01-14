/*
 * 팬그램
 * https://www.acmicpc.net/problem/10384
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	cin.ignore();
	for (int i = 1; i <= t; i++) {
		string s;	getline(cin, s);
		vector<int> check(26);
		for (char c : s) {
			if ('a' <= c && c <= 'z')
				check[c - 'a']++;
			else if ('A' <= c && c <= 'Z')
				check[c - 'A']++;
		}
		int result = *min_element(check.begin(), check.end());
		if (result == 0)
			printf("Case %d: Not a pangram\n", i);
		else if (result == 1)
			printf("Case %d: Pangram!\n", i);
		else if (result == 2)
			printf("Case %d: Double pangram!!\n", i);
		else
			printf("Case %d: Triple pangram!!!\n", i);
	}
}