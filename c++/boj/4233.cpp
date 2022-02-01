/*
 * 가짜소수
 * https://www.acmicpc.net/problem/4233
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;

bool isPrime(int num) {
	if (num % 2 == 0) return false;
	for (int i = 3; i * i <= num; i += 2)
		if (num % i == 0) return false;
	return true;
}

ll fast_pow(ll base, ll exp, ll mod) {
	ll r = 1;
	base = base % mod;
	while (exp) {
		if (exp & 1)
			r = r * base % mod;
		base = (base * base) % mod;
		exp >>= 1;
	}
	return r;
}

int main() {
	while (1) {
		int p, a;	cin >> p >> a;
		if (p == 0 && a == 0) break;
		if (isPrime(p)) cout << "no\n";
		else if (fast_pow(a, p, p) == a) cout << "yes\n";
		else cout << "no\n";
	}
}