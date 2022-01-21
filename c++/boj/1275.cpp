/*
 * 커피숍2
 * https://www.acmicpc.net/problem/1275
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;
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
	vector<ll> num(n);
	for (ll &elem : num) cin >> elem;
	int s = 1; while (s < n) s *= 2;
	tree.resize(s * 2);
	for (int i = 0; i < n; i++)
		tree[s + i] = num[i];
	for (int i = s - 1; i > 0; i--)
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	for (int i = 0; i < q; i++) {
		int from, to, order; ll val;
		cin >> from >> to >> order >> val;
		if (from > to) swap(from, to);
		cout << get(s + from - 1, s + to - 1) << '\n';
		update(s + order - 1, val - tree[s + order - 1]);
	}
}