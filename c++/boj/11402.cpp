/*
 * 이항 계수 4
 * https://www.acmicpc.net/problem/11402
 */

#include "bits/stdc++.h"
using namespace std;
#define ll	long long
#define MAX		2010
ll binomial[MAX][MAX];

int main() {
	ll n, k, m;	cin >> n >> k >> m;
	for (int i = 0; i < m; i++) {
		binomial[i][0] = 1;
		for (int j = 1; j < i + 1; j++)
			binomial[i][j] = (binomial[i - 1][j - 1] + binomial[i - 1][j]) % m;
	}
	ll r = 1;
	while (n || k) {
		r *= binomial[n % m][k % m];
		n /= m;
		k /= m;
		r %= m;
	}
	cout << r;
}