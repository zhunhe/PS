/*
 * 숨바꼭질 4
 * https://www.acmicpc.net/problem/13913
 */

#include <bits/stdc++.h>
using namespace std;

int n, k, sec;
int dist[100002];

void print_ans() {
	cout << sec << '\n';
	stack<int> st;
	st.push(k);
	int next = dist[k];
	for (int i = 0; i < sec; i++) {
		st.push(next);
		next = dist[next];
	}
	while (st.size()) {
		cout << st.top() << ' ';
		st.pop();
	}
}

void BFS() {
	int L = 0;
	queue<int> q;	q.push(n);
	dist[n] = -1;
	while (!sec) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front(); q.pop();
			if (x == k) {
				sec = L;
				return;
			}
			for (int nx : {x - 1, x + 1, x * 2}) {
				if (nx < 0 || nx > 100000 || dist[nx] != -1) continue;
				q.push(nx);
				dist[nx] = x;
			}
		}
		L++;
	}
}

int main() {
	cin >> n >> k;
	if (n == k) {
		cout << 0 << '\n' << n;
		return 0;
	}
	memset(dist, -1, sizeof(dist));
	BFS();
	print_ans();
}