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

// ❗️주식을 구매, 판매하여 가장 높은 수익을 올리면 얼만지 구하는 문제
// 하루에 아래 중 하나의 행동을 할 수 있음
// 1. 주식 하나를 산다.
// 2. 원하는 만큼 가지고 있는 주식을 판다.
// 3. 아무것도 안한다.
long long GREEDY(vector<int> stock) {
	// 마지막값을 초기값으로 설정
	int max_val = stock[stock.size() - 1];
	stack<int> tmp;
	long long answer = 0;

	// 뒤에서부터 스택에 현재 max_val보다 큰 가격이 나오기 전까지 주식가격을 push
	// max_val보다 큰 가격이 나올 경우 'max_val - 스택에 들어있는 가격'을 answer에 저장
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
	// 0번 인덱스까지 도착했는데 스택에 값이 남아있는 경우
	// max_val보다 큰 가격이 나올 경우 'max_val - 스택에 들어있는 가격'을 answer에 저장
	while (tmp.size()) {
		answer += (max_val - tmp.top());
		tmp.pop();
	}
	return answer;
}

int main() {
	int t;

	cin >> t;
	while (t--) {
		cout << GREEDY(set_input_data()) << '\n';
	}
	return 0;
}