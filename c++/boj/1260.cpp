/*
 * DFS와 BFS
 * https://www.acmicpc.net/problem/1260
 */

#include "bits/stdc++.h"
using namespace std;

bool visited[1001];
vector<vector<int>> graph;

void dfs(int now) {
	if (visited[now]) return;
	visited[now] = true;
	cout << now << ' ';
	for (int next : graph[now])
		if (!visited[next])
			dfs(next);
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (visited[now]) continue;
		visited[now] = true;
		cout << now << ' ';
		for (int next : graph[now])
			q.push(next);
	}
}

int main() {
	int n, m, v, a, b;	cin >> n >> m >> v;
	graph.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());
	dfs(v);
	cout << "\n";
	memset(visited, false, sizeof(visited));
	bfs(v);
}