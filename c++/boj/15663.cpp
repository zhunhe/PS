/*
 * N과 M (9)
 * https://www.acmicpc.net/problem/15663
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
set<vector<int>> ans;
vector<int> num, tmp;
vector<bool> visited;

void dfs(int depth) {
	if (depth == m) {
		ans.insert(tmp);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		tmp.push_back(num[i]);
		dfs(depth + 1);
		visited[i] = false;
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	num.resize(n);
	for (int &elem : num) cin >> elem;
	visited.resize(n);
	dfs(0);
	for (auto v : ans) {
		for (auto elem : v)
			cout << elem << ' ';
		cout << '\n';
	}

}