/*
 * Maaaaaaaaaze
 * https://www.acmicpc.net/problem/16985
 */

#include "bits/stdc++.h"
using namespace std;
#define vvvi	vector<vector<vector<int>>>
#define vvi		vector<vector<int>>
#define vi		vector<int>
#define WALL	0
#define EMPTY	1
#define LEN		5
#define INF		987654321
int ans = INF;
vvvi board, maze, visited;
bool checked[LEN];
struct coor {
	int z, y, x;
};

const int dz[6] = {-1,1,0,0,0,0};
const int dy[6] = {0,0,-1,1,0,0};
const int dx[6] = {0,0,0,0,-1,1};
int bfs() {
	visited.resize(0);
	visited.resize(LEN, vvi(LEN, vi(LEN)));
	int t = 0;
	coor cur = {0,0,0};
	queue<coor> q;
	q.push(cur);
	visited[cur.z][cur.y][cur.x] = 1;
	while (!q.empty()) {
		const int len = q.size();
		for (int i = 0; i < len; i++) {
			cur = q.front();	q.pop();
			for (int k = 0; k < 6; k++) {
				coor next = {cur.z + dz[k], cur.y + dy[k], cur.x + dx[k]};
				if (next.z < 0 || next.y < 0 || next.x < 0) continue;
				if (next.z >= LEN || next.y >= LEN || next.x >= LEN) continue;
				if (visited[next.z][next.y][next.x]) continue;
				if (maze[next.z][next.y][next.x] == WALL) continue;
				if (next.z == LEN-1 && next.y == LEN-1 && next.x == LEN-1)
					return t + 1;
				visited[next.z][next.y][next.x] = 1;
				q.push(next);
			}
		}
		t++;
	}
	return -1;
}

void setMaze(int depth, int zIndex, int rotateCnt) {
	vvi rotated(LEN, vi(LEN));
	for (int i = 0; i < LEN; i++) {
		for (int j = 0; j < LEN; j++) {
			switch (rotateCnt) {
				case 0: rotated[i][j] = board[zIndex][i][j]; break;
				case 1:	rotated[j][LEN - 1 - i] = board[zIndex][i][j]; break;
				case 2:	rotated[LEN - 1 - i][LEN - 1 - j] = board[zIndex][i][j]; break;
				case 3:	rotated[LEN - 1 - j][i] = board[zIndex][i][j]; break;
			}
		}
	}
	for (int i = 0; i < LEN; i++)
		for (int j = 0; j < LEN; j++)
			maze[depth][i][j] = rotated[i][j];
}

bool findMin;
void dfs(int depth) {
	if (findMin) return;
	if (depth == LEN) {
		if (maze[LEN-1][LEN-1][LEN-1] == EMPTY) {
			int t = bfs();
			if (t != -1) ans = min(ans, t);
			if (ans == 12) findMin = true;
		}
		return;
	}
	for (int i = 0; i < LEN; i++) {
		if (checked[i]) continue;
		checked[i] = true;
		for (int k = 0; k < 4; k++) {
			setMaze(depth, i, k);
			if (maze[0][0][0] == EMPTY)
				dfs(depth + 1);
		}
		checked[i] = false;
	}
}

int main() {
	board.resize(LEN, vvi(LEN, vi(LEN)));
	maze.resize(LEN, vvi(LEN, vi(LEN)));
	for (vvi &vv : board) for (vi &v : vv) for (int &elem : v) cin >> elem;
	dfs(0);
	cout << (ans == INF ? -1 : ans);
}