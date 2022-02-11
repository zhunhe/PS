/*
 * 조합 (Combination)
 * https://www.acmicpc.net/problem/16134
 */

#include "bits/stdc++.h"
using namespace std;
#define ll	long long
#define MOD	1000000007

ll fast_pow(ll base, ll exp) {
	ll ret = 1;
	while (exp) {
		if (exp & 1) ret = (ret * base) % MOD;
		base = (base * base) % MOD;
		exp >>= 1;
	}
	return ret;
}

int main() {
	ll n, r, a = 1, b = 1, c = 1;
	cin >> n >> r;
	for (int i = 1; i < n + 1; i++)
		a = (a * i) % MOD;
	for (int i = 1; i < n - r + 1; i++)
		b = (b * i) % MOD;
	for (int i = 1; i < r + 1; i++)
		c = (c * i) % MOD;
	cout << (a * fast_pow(b, MOD - 2) % MOD) * fast_pow(c, MOD - 2) % MOD;
}