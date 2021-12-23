/*
 * 스타트링크
 * https://www.acmicpc.net/problem/5014
 */

#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d;
int ans;

void BFS(vector<bool> visit) {
	queue<int> q;
	q.push(s);
	visit[s] = true;
	int L = 1;
	while (q.size()) {
		const int len = q.size();
		for (int i = 0; i < len; i++) {
			const int y = q.front(); q.pop();
			for (int ny : {y + u, y - d}) {
				if (ny <= 0 || ny > f) continue;
				if (visit[ny]) continue;
				if (ny == g) {
					ans = L;
					return;
				}
				visit[ny] = true;
				q.push(ny);
			}
		}
		L++;
	}
}

int main() {
	cin >> f >> s >> g >> u >> d;
	if (s == g) {
		cout << 0;
		return 0;
	}
	vector<bool> visit(f + 1);
	BFS(visit);
	if (ans) cout << ans;
	else cout << "use the stairs";
}