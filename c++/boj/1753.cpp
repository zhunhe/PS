/*
 * 최단경로
 * https://www.acmicpc.net/problem/1753
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int v, e;	cin >> v >> e;
	int k;	cin >> k;
	vector<vector<pair<int, int>>> graph(v + 1);
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({to, cost});
	}
	vector<int> dist(v + 1, INT_MAX);
	dist[k] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({0, k});
	while (!pq.empty()) {
		int now = pq.top().second;
		int nowCost = -pq.top().first;
		pq.pop();
		for (auto to : graph[now]) {
			int next = to.first;
			int nextCost = nowCost + to.second;
			if (dist[next] <= nextCost) continue;
			dist[next] = nextCost;
			pq.push(make_pair(-nextCost, next));
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INT_MAX) cout << "INF\n";
		else cout << dist[i] << '\n';
	}
}