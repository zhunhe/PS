/*
 * N과 M (5)
 * https://www.acmicpc.net/problem/15654
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> num;
vector<bool> visited;
vector<int> tmp;

void dfs(int depth) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			tmp.push_back(num[i]);
			dfs(depth + 1);
			visited[i] = false;
			tmp.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;
	num.resize(n);
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	visited.resize(n);
	dfs(0);
}