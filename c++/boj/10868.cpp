/*
 * 최솟값
 * https://www.acmicpc.net/problem/10868
 */

#include "bits/stdc++.h"
using namespace std;

vector<int> tree;

int get_min(int s, int e) {
	int ret = 1e9;
	ret = min({ret, tree[s], tree[e]});
	while (s <= e) {
		if (s % 2 == 1) ret = min(ret, tree[s]);
		if (e % 2 == 0) ret = min(ret, tree[e]);
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
	tree.resize(s * 2);
	for (int i = 0; i < n; i++) tree[s + i] = num[i];
	for (int i = s - 1; i > 0; i--) tree[i] = min(tree[i * 2], tree[i * 2 + 1]);
	for (int i = 0; i < m; i++) {
		int from, to;	cin >> from >> to;
		cout << get_min(s + from - 1, s + to - 1) << '\n';
	}
}