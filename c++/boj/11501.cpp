/*
 * 주식
 * https://www.acmicpc.net/problem/11501
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--)	{
		int n;	cin >> n;
		vector<int> stock(n);
		for (auto &elem : stock) cin >> elem;
		int max_val = stock.back();
		stack<int> tmp;
		long long answer = 0;
		for (int i = stock.size() - 2; i >= 0; i--) {
			if (stock[i] >= max_val) {
				while (tmp.size()) {
					answer += (max_val - tmp.top());
					tmp.pop();
				}
				max_val = stock[i];
				continue;
			}
			tmp.push(stock[i]);
		}
		while (tmp.size()) {
			answer += (max_val - tmp.top());
			tmp.pop();
		}
		cout << answer << '\n';
	}
}