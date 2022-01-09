/*
 * 단지번호붙이기
 * https://www.acmicpc.net/problem/2667
 */

#include "bits/stdc++.h"
using namespace std;

int n, len;
vector<vector<char>> coor;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};

void DFS(int y, int x) {
	for (int k = 0; k < 4; k++) {
		const int ny = y + dy[k];
		const int nx = x + dx[k];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (coor[ny][nx] == '0') continue;
		coor[ny][nx] = '0';
		len++;
		DFS(ny, nx);
	}
}

int main() {
	cin >> n;
	coor.resize(n, vector<char>(n));
	for (int i = 0; i < n * n; i++)
		cin >> coor[i / n][i % n];
	vector<int> ans;
	for (int i = 0; i < n * n; i++) {
		if (coor[i / n][i % n] == '0') continue;
		coor[i / n][i % n] = '0';
		len = 1;
		DFS(i / n, i % n);
		ans.push_back(len);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int num : ans) cout << num << '\n';
}