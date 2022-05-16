/*
 * 파일 합치기 3
 * https://www.acmicpc.net/problem/13975
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int tc;	cin >> tc;
	while (tc--) {
		int64_t ans = 0;
		int n;	cin >> n;
		priority_queue<int64_t> pq;
		for (int i = 0; i < n; i++) {
			int tmp;	cin >> tmp;
			pq.push(-tmp);
		}
		while (pq.size() >= 2) {
			int64_t val1 = pq.top();	pq.pop();
			int64_t val2 = pq.top();	pq.pop();
			ans += val1 + val2;
			pq.push(val1 + val2);
		}
		cout << -ans << '\n';
	}
}