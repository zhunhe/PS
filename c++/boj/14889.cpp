/*
 * 스타트와 링크
 * https://www.acmicpc.net/problem/14889
 */

#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
int stat[20][20];
bool visit[20];

void DFS(int L, int s) {
	if (L == n/2) {
		vector<int> team_s, team_l;
		for (int i = 0; i < n; i++) {
			if (visit[i]) team_s.push_back(i);
			else team_l.push_back(i);
		}
		int sum_s = 0, sum_l = 0;
		for (int i = 0; i < n/2; i++) {
			for (int j = 0; j < n/2; j++) {
				sum_s += stat[team_s[i]][team_s[j]];
				sum_l += stat[team_l[i]][team_l[j]];
			}
		}
		ans = min(ans, abs(sum_s - sum_l));
		return;
	}
	for (int i = s; i < n; i++) {
		if (visit[i]) continue;
		visit[i] = true;
		DFS(L + 1, i);
		visit[i] = false;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n * n; i++)
		cin >> stat[i/n][i%n];
	DFS(0, 0);
	cout << ans;
}