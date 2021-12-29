/*
 * 주식
 * https://www.acmicpc.net/problem/11501
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <bits/stdc++.h>
using namespace std;

vector<int> set_input_data() {
	FAST_IO();
	int n;	cin >> n;
	vector<int> stock(n);
	for (int i = 0; i < n; i++)
		cin >> stock[i];
	return stock;
}

long long GREEDY(vector<int> stock) {
	int max_val = stock[stock.size() - 1];
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
	return answer;
}

int main() {
	int t;	cin >> t;
	while (t--)	cout << GREEDY(set_input_data()) << '\n';
}