/*
 * 탑
 * https://www.acmicpc.net/problem/2493
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <vector>
#include <stack>

int main() {
	FAST_IO();
	int n;	std::cin >> n;
	std::vector<int> tower(n), ans(n);
	for (int i = 0; i < n; i++)
		std::cin >> tower[i];
	std::stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		while (st.size() && tower[i] > tower[st.top()]) {
			ans[st.top()] = i + 1;
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < ans.size(); i++)
		std::cout << ans[i] << ' ';
}