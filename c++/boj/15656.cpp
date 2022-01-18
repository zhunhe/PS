/*
 * N과 M (7)
 * https://www.acmicpc.net/problem/15656
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> num, tmp;

void dfs(int depth) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
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
	sort(num.begin(), num.end());
	dfs(0);
}