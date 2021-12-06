/*
 * 주식
 * https://www.acmicpc.net/problem/11501
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	vector<int> stock;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		stock.push_back(tmp);
	}
	return stock;
}

long long solve_GREEDY(vector<int> stock) {
	int max = stock[stock.size() - 1];
	stack<int> tmp;
	long long answer = 0;

	for (int i = stock.size() - 2; i >= 0; i--) {
		if (stock[i] >= max) {
			while (tmp.size()) {
				answer += (max - tmp.top());
				tmp.pop();
			}
			max = stock[i];
		} else {
			tmp.push(stock[i]);
		}
	}
	while (tmp.size()) {
		answer += (max - tmp.top());
		tmp.pop();
	}
	return answer;
}

int main() {
	int t;

	cin >> t;
	while (t--) {
		cout << solve_GREEDY(set_input_data()) << '\n';
	}
	return 0;
}