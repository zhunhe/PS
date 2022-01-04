/*
 * 덱
 * https://www.acmicpc.net/problem/10866
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	string cmd;
	deque<string> dq;

	while (n-- >= 0) {
		getline(cin, cmd);
		if (cmd == "size")
			cout << dq.size() << '\n';
		else if (cmd == "empty")
			cout << (dq.empty() ? 1 : 0) << '\n';
		else if (cmd == "front")
			cout << (dq.empty() ? "-1" : dq.front()) << '\n';
		else if (cmd == "back")
			cout << (dq.empty() ? "-1" : dq.back()) << '\n';
		else if (cmd == "pop_back") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "pop_front") {
			if (dq.empty())
				cout << -1 << '\n';
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (cmd.substr(0, 9) == "push_back")
			dq.push_back(cmd.substr(10, cmd.size() + 1));
		else if (cmd.substr(0, 10) == "push_front")
			dq.push_front(cmd.substr(11, cmd.size() + 1));
	}
}