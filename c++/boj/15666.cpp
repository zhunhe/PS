/*
 * N과 M (12)
 * https://www.acmicpc.net/problem/15666
 */

#include "bits/stdc++.h"
using namespace std;

int n, m;
vector<int> num;
vector<int> tmp;

void dfs(int depth, int start) {
	if (depth == m) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < num.size(); i++) {
		tmp.push_back(num[i]);
		dfs(depth + 1, i);
		tmp.pop_back();
	}
}

int main() {
	cin >> n >> m;
	num.resize(n);
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	dfs(0, 0);
}