/*
 * 곱셈
 * https://www.acmicpc.net/problem/1629
 */

#include "bits/stdc++.h"
using namespace std;
typedef unsigned long long ull;

#define MAX		1<<20
ull base, mod;

ull power(ull n) {
	if (n == 1)
		return base % mod;
	if (n == 0 || base == 1)
		return 1;
	if (n % 2)
		return power(n/2) * power(n/2+1) % mod;
	else
		return power(n/2) * power(n/2) % mod;
}

int main() {
	ull n;	cin >> base >> n >> mod;
	cout << power(n) << '\n';
}