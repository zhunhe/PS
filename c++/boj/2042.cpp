/*
 * 구간 합 구하기
 * https://www.acmicpc.net/problem/2042
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;
#define MAXN	1000001
ll arr[MAXN], tree[MAXN];
int n, m, k;

void update(int x, ll value) {
	while (x <= n) {
		tree[x] += value;
		x += (x & -x);
	}
}

ll query(int x) {
	ll ret = 0;
	while (x >= 1) {
		ret += tree[x];
		x -= (x & -x);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i < n + 1; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	for (int i = 0; i < m + k; i++) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int x; ll value;	cin >> x >> value;
			update(x, value - arr[x]);
			arr[x] = value;
		} else {
			int from, to;	cin >> from >> to;
			cout << query(to) - query(from - 1) << '\n';
		}
	}
}