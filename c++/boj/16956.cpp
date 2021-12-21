/*
 * 늑대와 양
 * https://www.acmicpc.net/problem/16956
 */

#include <iostream>
using namespace std;

#define EMPTY	'.'
#define SHEEP	'S'
#define WOLF	'W'
#define FENCE	'D'

int r, c;
char map[500][500];

bool is_possible() {
	const int dy[4] = {-1,0,1,0};
	const int dx[4] = {0,1,0,-1};
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != SHEEP) continue;
			for (int k = 0; k < 4; k++) {
				const int ny = i + dy[k];
				const int nx = j + dx[k];
				if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
				if (map[ny][nx] == WOLF) return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r ; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	if (is_possible()) {
		cout << 1 << '\n';
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j] == EMPTY) cout << FENCE;
				else cout << map[i][j];
			}
			cout << '\n';
		}
	} else cout << 0;
}
