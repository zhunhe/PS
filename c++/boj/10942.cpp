/*
 * 팰린드롬?
 * https://www.acmicpc.net/problem/10942
 */

#include "bits/stdc++.h"
using namespace std;
#define MAXN	2001
int n, seq[MAXN], cache[MAXN][MAXN];

int dp(int s, int e) {
	if (cache[s][e] != -1) return cache[s][e];
	int &ret = cache[s][e];
	if (s == e) return ret = 1;
	if (s + 1 == e) return ret = (seq[s] == seq[e]);
	if (seq[s] != seq[e]) return 0;
	return ret = dp(s + 1, e - 1);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(cache, -1, sizeof(cache));
	int n;	cin >> n;
	for (int i = 1; i < n + 1; i++) cin >> seq[i];
	int m;	cin >> m;
	while (m--) {
		int s, e;	cin >> s >> e;
		cout << dp(s, e) << '\n';
	}
}