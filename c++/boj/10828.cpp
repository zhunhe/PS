/*
 * 스택
 * https://www.acmicpc.net/problem/10828
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	stack<string> st;
	while (n--) {
		string cmd;	cin >> cmd;
		if (cmd == "push") {
			string num;	cin >> num;
			st.push(num);
		}
		if (cmd == "pop") {
			if (st.empty()) {
				cout << -1 << '\n';
			} else {
				cout << st.top() << '\n';
				st.pop();
			}
		}
		else if (cmd == "size")
			cout << st.size() << '\n';
		else if (cmd == "empty")
			cout << (st.empty() ? 1 : 0) << '\n';
		else if (cmd == "top")
			cout << (st.empty() ? "-1" : st.top()) << '\n';
	}
}