/*
 * N과 M (2)
 * https://www.acmicpc.net/problem/15650
 */

#include "bits/stdc++.h"
using namespace std;

vector<bool> visited;
int n, m;

void dfs(int depth, int start) {
	if (depth == m) {
		for (int i = 0; i < n; i++)
			if (visited[i])
				cout << i + 1 << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(depth + 1, i);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	visited.resize(n);
	dfs(0, 0);
}