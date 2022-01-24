/*
 * 최소 스패닝 트리
 * https://www.acmicpc.net/problem/1197
 */

#include "bits/stdc++.h"
using namespace std;

struct adjData {
	int weight, from, to;
};

int main() {
	int v, e, ans = 0;	cin >> v >> e;
	vector<adjData> adj(v + 1);
	for (int i = 0; i < e; i++) {
		int from, to, weight;
		cin >> from >> to >> weight;
		adj.push_back({weight, from, to});
	}
	sort(adj.begin(), adj.end(),
		 [&](adjData first, adjData second) -> bool {
		return first.weight < second.weight;
	});
	vector<int> unf(v + 1);
	for (int i = 0; i < v + 1; i++) unf[i] = i;

	auto Find = [&](auto &self, int n) {
		if (n == unf[n]) return n;
		return unf[n] = self(self, unf[n]);
	};
	for (adjData elem : adj) {
		const int fa = Find(Find, elem.from);
		const int fb = Find(Find, elem.to);
		if (fa != fb) {
			unf[fa] = fb;
			ans += elem.weight;
		}
	}
	cout << ans;
}