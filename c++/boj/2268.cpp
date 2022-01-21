/*
 * 수들의 합 7
 * https://www.acmicpc.net/problem/2003
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;
#define SUM		0
#define MODIFY	1
vector<ll> tree;

ll get(int s, int e) {
	ll sum = 0;
	while (s <= e) {
		if (s % 2 == 1) sum += tree[s];
		if (e % 2 == 0) sum += tree[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return sum;
}

void update(int node, ll val) {
	while (node > 0) {
		tree[node] += val;
		node /= 2;
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;	cin >> n >> m;
	int s = 1; while (s < n) s *= 2;
	tree.resize(s * 2);
	for (int i = 0; i < m; i++) {
		int cmd;	cin >> cmd;
		if (cmd == SUM) {
			int from, to;	cin >> from >> to;
			if (from > to) swap(from, to);
			cout << get(s + from - 1, s + to - 1) << '\n';
		} else if (cmd == MODIFY) {
			int order; ll val;	cin >> order >> val;
			update(s + order - 1, val - tree[s + order - 1]);
		}
	}
}