/*
 * 크게 만들기
 * https://www.acmicpc.net/problem/2812
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	string s;	cin >> s;
	deque<char> dq;
	for (auto c : s) {
		while (dq.size() && c > dq.back() && k-- > 0) dq.pop_back();
		dq.push_back(c);
	}
	while (k-- > 0) dq.pop_back();
	while (dq.size()) {
		cout << dq.front();
		dq.pop_front();
	}
}