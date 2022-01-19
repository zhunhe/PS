/*
 * 로또
 * https://www.acmicpc.net/problem/6603
 */

#include "bits/stdc++.h"
using namespace std;

int k;
vector<int> num, tmp;

void dfs(int depth, int start) {
	if (depth == 6) {
		for (int elem : tmp)
			cout << elem << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < k; i++) {
		tmp.push_back(num[i]);
		dfs(depth + 1, i + 1);
		tmp.pop_back();
	}
}

int main() {
	while (1) {
		cin >> k;
		if (k == 0)
			return 0;
		num.resize(k);
		for (int &elem : num) cin >> elem;
		sort(num.begin(), num.end());
		dfs(0, 0);
		cout << '\n';
	}
}