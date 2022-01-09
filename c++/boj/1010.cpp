/*
 * 다리 놓기
 * https://www.acmicpc.net/problem/1010
 */

#include "bits/stdc++.h"
using namespace std;

#define MAX		30
int cache[MAX][MAX];

int comb(int n, int r) {
	if (cache[n][r]) return cache[n][r];
	int &ret = cache[n][r];
	if (r == 1)
		return ret = n;
	if (r == 0 || r == n)
		return ret = 1;
	return ret = comb(n-1, r-1) + comb(n-1, r);
}

int main() {
	int t;	cin >> t;
	while (t--) {
		int n, r;	cin >> r >> n;
		cout << comb(n, r) << '\n';
	}
}