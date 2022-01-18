/*
 * N과 M (4)
 * https://www.acmicpc.net/problem/15652
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> tmp;

void dfs(int depth, int start) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		tmp.push_back(i + 1);
		dfs(depth + 1, i);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs(0, 0);
}