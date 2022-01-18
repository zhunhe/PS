/*
 * 부분수열의 합
 * https://www.acmicpc.net/problem/1182
 */

#include "bits/stdc++.h"
using namespace std;

int n, s, ans;
vector<int> num, visited;

void dfs(int depth, int start, int sum) {
	if (depth && sum == s)
		ans++;
	if (depth == n)
		return;
	for (int i = start; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(depth + 1, i + 1, sum + num[i]);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> s;
	num.resize(n);
	visited.resize(n);
	for (int &elem : num) cin >> elem;
	dfs(0, 0, 0);
	cout << ans;
}