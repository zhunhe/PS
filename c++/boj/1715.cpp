/*
 * 카드 정렬하기
 * https://www.acmicpc.net/problem/1715
 */

#include "bits/stdc++.h"
using namespace std;

int ans;

int main() {
	int n;	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		int tmp;	cin >> tmp;
		pq.push(-tmp);
	}
	while (pq.size() >= 2) {
		int val1 = pq.top();	pq.pop();
		int val2 = pq.top();	pq.pop();
		ans += val1 + val2;
		pq.push(val1 + val2);
	}
	cout << -ans;
}
