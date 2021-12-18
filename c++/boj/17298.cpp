/*
 * 오큰수
 * https://www.acmicpc.net/problem/17298
 */

#include <iostream>
#include <vector>
#include <stack>

int main() {
	int n;	std::cin >> n;
	std::vector<int> num(n), ans(n, -1);
	for (int &elem : num) std::cin >> elem;
	std::stack<int> st;
	for (int i = 0; i < n; i++) {
		while (st.size() && num[i] > num[st.top()]) {
			ans[st.top()] = num[i];
			st.pop();
		}
		st.push(i);
	}
	for (auto elem: ans)
		std::cout << elem << ' ';
}