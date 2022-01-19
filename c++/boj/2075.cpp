/*
 * N번째 큰 수
 * https://www.acmicpc.net/problem/2075
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;	cin >> n;
	priority_queue<int> pq;
	for (int i = 0; i < n * n; i++) {
		int tmp;	cin >> tmp;
		if (pq.empty() || pq.size() < n)
			pq.push(-tmp);
		if (pq.size() == n && -pq.top() < tmp) {
			pq.pop();
			pq.push(-tmp);
		}
	}
	cout << -pq.top();
}
