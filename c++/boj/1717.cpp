/*
 * 집합의 표현
 * https://www.acmicpc.net/problem/1717
 */

#include "bits/stdc++.h"
using namespace std;
#define UNION	0
#define FIND	1

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;	cin >> n >> m;
	vector<int> parent(n + 1, -1);
	auto Find = [&](auto &self, int n) {
		if (parent[n] < 0) return n;
		return parent[n] = self(self, parent[n]);
	};
	auto Union = [&](int u, int v) {
		u = Find(Find, u), v = Find(Find, v);
		if (u != v) {
			if (parent[u] > parent[v]) swap(u, v);
			parent[u] += parent[v];
			parent[v] = u;
		}
	};
	while (m--){
		int cmd, a, b;	cin >> cmd >> a >> b;
		if (cmd == UNION) Union(a, b);
		else cout << (Find(Find, a) == Find(Find, b) ? "YES\n" : "NO\n");
	}
}