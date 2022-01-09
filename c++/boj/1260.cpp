/*
 * DFS와 BFS
 * https://www.acmicpc.net/problem/1260
 */

#include "bits/stdc++.h"
using namespace std;

vector<vector<int>> graph;
vector<int> check;
int vertex, edge, start;

void dfs(int now) {
	for (int next : graph[now]) {
		if (check[next]) continue;
		check[next] = 1;	cout << next << ' ';	dfs(next);
	}
}

void bfs() {
	queue<int> q;
	check.resize(vertex + 1);
	check[start] = 1;	cout << start << ' ';	q.push(start);
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int next : graph[now]) {
			if (check[next]) continue;
			check[next] = 1;	cout << next << ' ';	q.push(next);
		}
	}
}

int main() {
	cin >> vertex >> edge >> start;
	graph.resize(vertex + 1);
	for (int i = 0; i < edge; i++) {
		int a, b;	cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= vertex; i++)
		sort(graph[i].begin(), graph[i].end());
	check.resize(0);	check.resize(vertex + 1, 0);
	check[start] = 1;	cout << start << ' ';
	dfs(start);
	cout << '\n';
	check.resize(0);	check.resize(vertex + 1, 0);
	bfs();
}