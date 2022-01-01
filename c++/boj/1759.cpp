/*
 * 연구소
 * https://www.acmicpc.net/problem/14502
 */

#include <bits/stdc++.h>
using namespace std;

int l, c;
char alpha[15];
vector<char> tmp;

bool is_valid(vector<char> s) {
	int c_count = 0, v_count = 0;
	for (auto c : s) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			v_count++;
		else
			c_count++;
	}
	if (v_count >= 1 && c_count >= 2)
		return true;
	return false;
}

void DFS(int L, int s) {
	if (L == l) {
		if (is_valid(tmp)) {
			for (int i = 0; i < l; i++)
				cout << tmp[i];
			cout << '\n';
		}
		return;
	}
	for (int i = s; i < c; i++) {
		tmp.push_back(alpha[i]);
		DFS(L + 1, i + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) cin >> alpha[i];
	sort(alpha, alpha + c);
	DFS(0, 0);
}