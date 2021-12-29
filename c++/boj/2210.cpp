/*
 * 숫자판 점프
 * https://www.acmicpc.net/problem/2210
 */

#include <bits/stdc++.h>
using namespace std;

#define N		5
char map[N][N];
set<string> ans;

const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void DFS(int L, int y, int x, string tmp) {
	if (L == 6) {
		ans.insert(tmp);
		return;
	}
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
		tmp[L] = map[ny][nx];
		DFS(L + 1, ny, nx, tmp);
	}
}

int main() {
	for (int i = 0; i < N * N; i++) cin >> map[i/N][i%N];
	for (int i = 0; i < N * N; i++) {
		string tmp = "000000";
		tmp[0] = map[i/N][i%N];
		DFS(0, i/N, i%N, tmp);
	}
	cout << ans.size();
}