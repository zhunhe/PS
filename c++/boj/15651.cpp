/*
 * N과 M (3)
 * https://www.acmicpc.net/problem/15651
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> tmp;

void dfs(int depth) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		tmp.push_back(i + 1);
		dfs(depth + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}