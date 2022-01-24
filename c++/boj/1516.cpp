/*
 * 게임 개발
 * https://www.acmicpc.net/problem/1516
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> time(n + 1), indeg(n + 1), dist(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> time[i];
		while (1) {
			int num; cin >> num;
			if (num == -1) break;
			indeg[i]++;
			adj[num].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i < n + 1; i++) {
		if (indeg[i] == 0) {
			q.push(i);
			dist[i] = time[i];
		}
	}
	while (!q.empty()) {
		int from = q.front();	q.pop();
		for (int to : adj[from]) {
			indeg[to]--;
			if (indeg[to] == 0)
				q.push(to);
			dist[to] = max(dist[to], dist[from] + time[to]);
		}
	}
	for (int i = 1; i < n + 1; i++)
		cout << dist[i] << '\n';
}