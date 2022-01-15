/*
 * 문자열 반복
 * https://www.acmicpc.net/problem/2675
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int time;	cin >> time;
		string s;	cin >> s;
		for (char c : s)
			for (int i = 0; i < time; i++)
				cout << c;
		cout << '\n';
	}
}