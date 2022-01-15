/*
 * 단어의 공부
 * https://www.acmicpc.net/problem/1157
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string s;	getline(cin, s);
	vector<int> check(26);
	for (char c : s) {
		if ('a' <= c && c <= 'z')
			check[c - 'a']++;
		else if ('A' <= c && c <= 'Z')
			check[c - 'A']++;
	}
	int mostUsed = -1;
	int count = 0;
	char ans;
	for (int i = 0; i < 26; i++) {
		if (mostUsed == check[i])
			count++;
		if (check[i] > mostUsed) {
			mostUsed = check[i];
			count = 0;
			ans = 'A' + i;
		}
	}
	cout << (count > 0 ? '?' : (char)ans);
}