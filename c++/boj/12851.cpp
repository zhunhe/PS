/*
 * 숨바꼭질 2
 * https://www.acmicpc.net/problem/12851
 */

#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int n, k, sec, cnt;
int dist[100002];

void BFS() {
	queue<int> q;
	q.push(n);
	int L = 0;
	while (!cnt) {
		int len = q.size();
		for (int i = 0; i < len; i++) {
			int x = q.front(); q.pop();
			if (x == k) {
				sec = L;
				cnt++;
			}
			for (int nx : {x - 1, x + 1, x * 2}) {
				if (nx < 0 || nx > 100000) continue;
				if (dist[nx] && dist[nx] != dist[x] + 1) continue;
				if (nx == n) continue;
				q.push(nx);
				dist[nx] = dist[x]+1;
			}
		}
		L++;
	}
}

int main() {
	cin >> n >> k;
	BFS();
	cout << sec << '\n' << cnt;
}