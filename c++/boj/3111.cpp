/*
 * 검열
 * https://www.acmicpc.net/problem/3111
 */

#include "bits/stdc++.h"
using namespace std;

#define TO_RIGHT	1

int main() {
	string t, a;	cin >> t >> a;
	int low = 0, high = a.size() - 1, dir = TO_RIGHT;
	deque<char> left, right;
	while (low <= high) {
		bool find = false;
		if (dir == TO_RIGHT) {
			left.push_back(a[low++]);
			if (left.size() < t.size()) continue;
			find = true;
			for (int i = 0; i < t.size(); i++) {
				if (t[i] != left[left.size() - t.size() + i]) {
					find = false;
					break;
				}
			}
			if (!find) continue;
			for (int i = 0; i < t.size(); i++) left.pop_back();
			dir *= -1;
		} else {
			right.push_front(a[high--]);
			if (right.size() < t.size()) continue;
			find = true;
			for (int i = 0; i < t.size(); i++) {
				if (t[i] != right[i]) {
					find = false;
					break;
				}
			}
			if (!find) continue;
			for (int i = 0; i < t.size(); i++) right.pop_front();
			dir *= -1;
		}
	}
	string ans = "";
	for (char elem : left) ans += elem;
	for (char elem : right) ans += elem;
	while (ans.find(t) != string::npos)
		ans.erase(ans.find(t), t.size());
	cout << ans;
}