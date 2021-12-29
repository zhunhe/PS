/*
 * 탑
 * https://www.acmicpc.net/problem/2493
 */

#include <bits/stdc++.h>

int main() {
	int n;	std::cin >> n;
	std::vector<int> tower(n), ans(n);
	for (auto &elem : tower) std::cin >> elem;
	std::stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && tower[i] > tower[st.top()]) {
			ans[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	for (auto elem : ans) std::cout << elem << ' ';
}