/*
 * 소수 구하기
 * https://www.acmicpc.net/problem/1929
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	long m, n;	cin >> m >> n;
	vector<int> prime(n + 1);
	for (int i = 2; i <= n; i++)
		prime[i] = i;
	for (int i = 2; i * i <= n; i++) {
		if (prime[i] == 0) continue;
		for (int j = i * i; j <= n; j += i) {
			prime[j] = 0;
		}
	}
	for (int i = m; i <= n; i++)
		if (prime[i])
			cout << prime[i] << '\n';
}