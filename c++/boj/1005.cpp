/*
 * ACM Craft
 * https://www.acmicpc.net/problem/1005
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t, from, to;	cin >> t;
	while (t--) {
		int n, k;	cin >> n >> k;
		vector<int> time(n + 1), indeg(n + 1), dist(n + 1);
		for (int i = 1; i < n + 1; i++) cin >> time[i];
		vector<vector<int>> adj(n + 1);
		for (int i = 0; i < k; i++) {
			cin >> from >> to;
			adj[from].push_back(to);
			indeg[to]++;
		}
		int w;	cin >> w;
		queue<int> q;
		for (int i = 1; i < n + 1; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				dist[i] = time[i];
			}
		}
		while (!q.empty()) {
			from = q.front();	q.pop();
			if (from == w) break;
			for (int to : adj[from]) {
				indeg[to]--;
				if (indeg[to] == 0)
					q.push(to);
				dist[to] = max(dist[to], dist[from] + time[to]);
			}
		}
		cout << dist[w] << '\n';
	}
}