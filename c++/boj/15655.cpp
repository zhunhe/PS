/*
 * N과 M (6)
 * https://www.acmicpc.net/problem/15655
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> num, tmp;

void dfs(int depth, int start) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
	}
	for (int i = start; i < n; i++) {
		tmp.push_back(num[i]);
		dfs(depth + 1, i + 1);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	num.resize(n);
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	dfs(0, 0);
}
