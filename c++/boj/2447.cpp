/*
 * 별 찍기 - 10
 * https://www.acmicpc.net/problem/2447
 */

#include <bits/stdc++.h>
using namespace std;

bool ch[2200][2200];

void divide_and_conquer(int y, int x, int len) {
	if (len == 1) {
		ch[y][x] = true;
		return;
	}
	divide_and_conquer(y, x, len/3);
	divide_and_conquer(y, x + len/3, len/3);
	divide_and_conquer(y, x + len/3 * 2, len/3);

	divide_and_conquer(y + len/3, x, len/3);
	divide_and_conquer(y + len/3, x + len/3 * 2, len/3);

	divide_and_conquer(y + len/3 * 2, x, len/3);
	divide_and_conquer(y + len/3 * 2, x + len/3, len/3);
	divide_and_conquer(y + len/3 * 2, x + len/3 * 2, len/3);
}

int main() {
	int n;	cin >> n;
	divide_and_conquer(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (ch[i][j] ? '*' : ' ');
		cout << '\n';
	}
}