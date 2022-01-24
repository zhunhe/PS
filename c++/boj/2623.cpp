/*
 * 음악프로그램
 * https://www.acmicpc.net/problem/2623
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	vector<int> indeg(n + 1), ans;
	vector<vector<int>> adj(n + 1);
	while (m--) {
		int num;	cin >> num;
		vector<int> tmp(num);
		for (int &elem : tmp) cin >> elem;
		for (int i = 1; i < num; i++) indeg[tmp[i]]++;
		for (int i = 0; i < num - 1; i++) adj[tmp[i]].push_back(tmp[i + 1]);
	}
	queue<int> q;
	for (int i = 1; i < n + 1; i++)
		if (indeg[i] == 0) {
			q.push(i);
			ans.push_back(i);
		}
	while (!q.empty()) {
		const int from = q.front(); q.pop();
		for (int to : adj[from]) {
			indeg[to]--;
			if (indeg[to] == 0) {
				q.push(to);
				ans.push_back(to);
			}
		}
	}
	if (ans.size() != n)
		cout << 0;
	else
		for (int elem : ans)
			cout << elem << '\n';
}