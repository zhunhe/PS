/*
 * 최솟값과 최댓값
 * https://www.acmicpc.net/problem/2357
 */

#include "bits/stdc++.h"
using namespace std;

vector<int> tree_max, tree_min;

int get_max(int s, int e) {
	int ret = 0;
	ret = max({ret, tree_max[s], tree_max[e]});
	while (s <= e) {
		if (s % 2 == 1) ret = max(ret, tree_max[s]);
		if (e % 2 == 0) ret = max(ret, tree_max[e]);
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

int get_min(int s, int e) {
	int ret = 1e9;
	ret = min({ret, tree_max[s], tree_max[e]});
	while (s <= e) {
		if (s % 2 == 1) ret = min(ret, tree_min[s]);
		if (e % 2 == 0) ret = min(ret, tree_min[e]);
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;	cin >> n >> m;
	vector<int> num(n);
	for (int &elem : num) cin >> elem;
	int s = 1; while (s < n) s *= 2;
	tree_max.resize(s * 2);
	tree_min.resize(s * 2);
	for (int i = 0; i < n; i++)
		tree_max[s + i] = tree_min[s + i] = num[i];
	for (int i = s - 1; i > 0; i--) {
		tree_max[i] = max(tree_max[i * 2], tree_max[i * 2 + 1]);
		tree_min[i] = min(tree_min[i * 2], tree_min[i * 2 + 1]);
	}
	for (int i = 0; i < m; i++) {
		int from, to;	cin >> from >> to;
		cout << get_min(s + from - 1, s + to - 1) << ' ' << get_max(s + from - 1, s + to - 1) << '\n';
	}
}