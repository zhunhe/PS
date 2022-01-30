/*
 * 노트북의 주인을 찾아서
 * https://www.acmicpc.net/problem/1298
 */

#include "bits/stdc++.h"
using namespace std;
#define MAX		5001
vector<int> adj[MAX];
int	matched[MAX];
bool checked[MAX];

bool dfs(int x) {
	for (int i = 0; i < adj[x].size(); i++) {
		int t = adj[x][i];
		if (checked[t]) continue;
		checked[t] = true;
		if (matched[t] == 0 || dfs(matched[t])) {
			matched[t] = x;
			return true;
		}
	}
	return false;
}

int main() {
	int n, m;	cin >> n >> m;
	for (int i = 1; i < m + 1; i++) {
		int a, b;	cin >> a >> b;
		adj[a].push_back(b);
	}
	int count = 0;
	for (int i = 1; i < n + 1; i++) {
		memset(checked, false, sizeof(checked));
		if (dfs(i)) count++;
	}
	cout << count;
}