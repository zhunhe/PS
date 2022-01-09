/*
 * 이항 계수 2
 * https://www.acmicpc.net/problem/11051
 */

#include "bits/stdc++.h"
using namespace std;

int cache[1001][1001];

int comb(int n, int r) {
	if (cache[n][r]) return cache[n][r];
	int &ret = cache[n][r];
	if (r == 0 || n == r)
		return ret = 1;
	else if (r == 1)
		return ret = n;
	else
		return ret = (comb(n-1, r-1) + comb(n-1, r)) % 10007;
}

int main() {
	int n, r;	cin >> n >> r;
	cout << comb(n, r) << '\n';
}