/*
 * N과 M (1)
 * https://www.acmicpc.net/problem/15649
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<bool> visited;
vector<int> tmp;

void dfs(int depth) {
	if (depth == m) {
		for (int i = 0; i < tmp.size(); i++)
			cout << tmp[i] << (i < tmp.size() - 1 ? ' ' : '\n');
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		tmp.push_back(i + 1);
		dfs(depth + 1);
		visited[i] = false;
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	visited.resize(n);
	dfs(0);
}