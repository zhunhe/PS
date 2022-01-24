/*
 * 도시 분할 계획
 * https://www.acmicpc.net/problem/1647
 */

#include "bits/stdc++.h"
using namespace std;

struct adjData {
	int weight, from, to;
};

int main() {
	int n, m, ans = 0, cnt = 0;	cin >> n >> m;
	vector<adjData> adj(n + 1);
	for (int i = 0; i < m; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		adj.push_back({weight, from, to});
	}
	sort(adj.begin(), adj.end(),
		 [&](adjData first, adjData second) -> bool {
		return first.weight < second.weight;
	});
	vector<int> unf(n + 1);
	for (int i = 0; i < n + 1; i++) unf[i] = i;
	auto Find = [&](auto &self, int n) {
		if (n == unf[n]) return n;
		return unf[n] = self(self, unf[n]);
	};
	for (adjData elem : adj) {
		const int fa = Find(Find, elem.from);
		const int fb = Find(Find, elem.to);
		if (fa != fb) {
			if (fa < fb)
				unf[fb] = fa;
			else
				unf[fa] = fb;
			ans += elem.weight;
			cnt++;
		}
		if (cnt == n - 2) break;
	}
	cout << ans;
}