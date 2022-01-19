/*
 * N과 M (11)
 * https://www.acmicpc.net/problem/15665
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
set<vector<int>> ans;
vector<int> num, tmp;

void dfs(int depth) {
	if (depth == m) {
		ans.insert(tmp);
		return;
	}
	for (int i = 0; i < n; i++) {
		tmp.push_back(num[i]);
		dfs(depth + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	num.resize(n);
	for (int &elem : num) cin >> elem;
	dfs(0);
	for (auto v : ans) {
		for (auto elem : v)
			cout << elem << ' ';
		cout << '\n';
	}

}