/*
 * 숨바꼭질 3
 * https://www.acmicpc.net/problem/13549
 */

#include "bits/stdc++.h"
using namespace std;

#define N_MAX	100001

int main() {
	int n, k;	cin >> n >> k;
	deque<int> dq;
	vector<int> dist(N_MAX, -1);
	dq.push_back(n), dist[n] = 0;
	while (!dq.empty()) {
		const int cur = dq.front(); dq.pop_front();
		if (cur == k) {
			cout << dist[cur];
			return 0;
		}
		for (const int next : {cur * 2, cur - 1, cur + 1}) {
			if (next < 0 || next > N_MAX || dist[next] >= 0) continue;
			if (next == cur * 2)
				dq.push_front(next), dist[next] = dist[cur];
			else
				dq.push_back(next), dist[next] = dist[cur] + 1;
		}
	}
}