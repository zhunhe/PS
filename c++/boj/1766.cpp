/*
 * 문제집
 * https://www.acmicpc.net/problem/1766
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m, from, to;	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> indeg(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
		indeg[to]++;
	}
	priority_queue<int> pq;
	for (int i = 1; i < n + 1; i++)
		if (indeg[i] == 0)
			pq.push(-i);
	while (!pq.empty()) {
		from = -pq.top();
		pq.pop();
		cout << from << ' ';
		for (int to : adj[from])
			if (--indeg[to] == 0)
				pq.push(-to);
	}
}