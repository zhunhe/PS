/*
 * 임계경로
 * https://www.acmicpc.net/problem/1948
 */

#include "bits/stdc++.h"
using namespace std;
struct adjData {
	int vertex, weight;
};

int main() {
	int v, e, start, finish, weight;	cin >> v >> e;
	vector<vector<adjData>> adj(v + 1), radj(v + 1);
	vector<int> indeg(v + 1), dist(v + 1);
	for (int i = 0; i < e; i++) {
		cin >> start >> finish >> weight;
		adj[start].push_back({finish, weight});
		radj[finish].push_back({start, weight});
		indeg[finish]++;
	}
	cin >> start >> finish;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();	q.pop();
		for (adjData next : adj[cur]) {
			if (--indeg[next.vertex] == 0)
				q.push(next.vertex);
			dist[next.vertex] = max(dist[next.vertex], dist[cur] + next.weight);
		}
	}
	int count = 0;
	q.push(finish);
	vector<int> visited(v + 1);
	while (!q.empty()) {
		int cur = q.front();	q.pop();
		for (adjData next : radj[cur]) {
			if (dist[cur] - dist[next.vertex] == next.weight) {
				count++;
				if (!visited[next.vertex]) {
					visited[next.vertex] = true;
					q.push(next.vertex);
				}
			}
		}
	}
	cout << dist[finish] << '\n' << count;
}