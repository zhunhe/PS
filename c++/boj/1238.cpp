/*
 * 파티
 * https://www.acmicpc.net/problem/1238
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, x;	cin >> n >> m >> x;
	vector<vector<pair<int, int>>> graph(n + 1);
	vector<vector<pair<int, int>>> graph2(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, cost;	cin >> from >> to >> cost;
		graph[from].push_back({cost, to});
		graph2[to].push_back({cost, from});
	}
	vector<int> dist(m + 1, INT_MAX);
	dist[x] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, x});
	while (pq.size()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		for (auto x : graph[now]) {
			int next = x.second;
			int next_cost = now_cost + x.first;
			if (next_cost >= dist[next]) continue;
			dist[next] = next_cost;
			pq.push({-next_cost, next});
		}
	}

	vector<int> dist2(m + 1, INT_MAX);
	dist2[x] = 0;
	pq.push({0, x});
	while (pq.size()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();
		for (auto x : graph2[now]) {
			int next = x.second;
			int next_cost = now_cost + x.first;
			if (next_cost >= dist2[next]) continue;
			dist2[next] = next_cost;
			pq.push({-next_cost, next});
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (dist[i] != INT_MAX && dist2[i] != INT_MAX)
			ans = max(ans, dist[i] + dist2[i]);
	cout << ans;
}