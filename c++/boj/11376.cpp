/*
 * 열혈강호 2
 * https://www.acmicpc.net/problem/11376
 */

#include "bits/stdc++.h"
using namespace std;
#define MAX		1001
vector<int> adj[MAX];
int matched[MAX];
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
	for (int i = 1; i < n + 1; i++) {
		int len;	cin >> len;
		while (len--) {
			int num;	cin >> num;
			adj[i].push_back(num);
		}
	}
	int count = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 0; j < 2; j++) {
			memset(checked, false, sizeof(checked));
			if (dfs(i)) count++;
		}
	}
	cout << count;
}