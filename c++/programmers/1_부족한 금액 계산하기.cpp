/*
 * 부족한 금액 계산하기
 * https://programmers.co.kr/learn/courses/30/lessons/82612
 */

#include "bits/stdc++.h"
using namespace std;

long long solution(int price, int money, int count)
{
	long long answer = money;
	int increase = price;
	for (int i = 0; i < count; i++) {
		answer -= price;
		price += increase;
	}
	return (answer >= 0 ? 0 : -answer);
}

int main() {
	vector<int> price{
		3
	};
	vector<int> money{
		20
	};
	vector<int> count{
		4
	};
	vector<int> want{
		10
	};
	for (int i = 0; i < want.size(); i++) {
		int got = solution(price[i], money[i], count[i]);
		cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}