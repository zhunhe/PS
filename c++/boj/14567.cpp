/*
 * 선수과목 (Prerequisite)
 * https://www.acmicpc.net/problem/14567
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m, from, to, semester = 1;	cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	vector<int> prereqCount(n + 1), ans(n + 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		adj[from].push_back(to);
		prereqCount[to]++;
	}
	queue<int> q;
	for (int i = 1; i < n; i++)
		if (prereqCount[i] == 0)
			q.push(i);
	while (!q.empty()) {
		const int len = q.size();
		for (int i = 0; i < len; i++) {
			from = q.front();	q.pop();
			for (int to : adj[from]) {
				prereqCount[to]--;
				if (prereqCount[to] == 0) {
					ans[to] = semester + 1;
					q.push(to);
				}
			}
		}
		semester++;
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}