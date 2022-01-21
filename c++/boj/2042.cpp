/*
 * 구간 합 구하기
 * https://www.acmicpc.net/problem/2042
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;

#define UPDATE	1
#define GET		2

vector<ll> num, arr;

void update(int node, ll val) {
	while (node > 0) {
		arr[node] += val;
		node /= 2;
	}
}

ll get(int s, int e) {
	ll sum = 0;
	while (s <= e) {
		if (s % 2 == 1) sum += arr[s];
		if (e % 2 == 0) sum += arr[e];
		s = (s + 1) / 2;
		e = (e - 1) / 2;
	}
	return sum;
}

int main() {
	int n, m, k;	cin >> n >> m >> k;
	num.resize(n);
	for (ll &elem : num) cin >> elem;
	int s = 1;	while (s < n) s *= 2;
	arr.resize(s * 2);
	for (int i = 0; i < n; i++)
		arr[s + i] = num[i];
	for (int i = s - 1; i > 0; i--)
		arr[i] = arr[i * 2] + arr[i * 2 + 1];
	for (int i = 0; i < m + k; i++) {
		int cmd; cin >> cmd;
		if (cmd == UPDATE) {
			int order; ll val;	cin >> order >> val;
			update(s + order - 1, val - arr[s + order - 1]);
		} else if (cmd == GET) {
			int from, to;	cin >> from >> to;
			cout << get(s + from - 1, s + to - 1) << '\n';
		}
	}
}