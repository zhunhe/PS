/*
 * 가계부 (Hard)
 * https://www.acmicpc.net/problem/12837
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;
#define UPDATE	1
#define GET		2
vector<ll> tree;

void update(int node, ll val) {
	while (node > 0) {
		tree[node] += val;
		node /= 2;
	}
}

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

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;	cin >> n >> q;
	int s = 1; while (s < n) s *= 2;
	tree.resize(s * 2);
	for (int i = 0; i < q; i++) {
		int cmd;	cin >> cmd;
		if (cmd == UPDATE) {
			int order; ll val;	cin >> order >> val;
			update(s + order - 1, val);
		} else if (cmd == GET) {
			int from, to;	cin >> from >> to;
			cout << get(s + from - 1, s + to - 1) << '\n';
		}
	}
}
