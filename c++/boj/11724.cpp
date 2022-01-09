/*
 * 연결 요소의 개수
 * https://www.acmicpc.net/problem/11724
 */

#include "bits/stdc++.h"
using namespace std;

bool visited[1001];
vector<vector<int>> graph(1001);

void dfs(int now) {
	if (visited[now]) return;
	visited[now] = true;
	for (int next : graph[now])
		if (!visited[next])
			dfs(next);
}

int main() {
	int n, m, a, b, ans;	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	ans = 0;
	for (int i = 1; i <= n; i++)
		if (!visited[i]) {
			ans++;
			dfs(i);
		}
	cout << ans;
}