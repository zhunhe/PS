/*
 * 단어 정렬
 * https://www.acmicpc.net/problem/1181
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<string> word(n);
	for (string &elem : word) cin >> elem;
	sort(word.begin(), word.end(), [&](string front, string back){
		if (front.size() == back.size())
			return front < back;
		return front.size() < back.size();
	});
	for (int i = 0; i < n; i++)
		if (i == 0 || word[i - 1] != word[i])
			cout << word[i] << '\n';
}