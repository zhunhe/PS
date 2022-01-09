/*
 * 이항 계수 1
 * https://www.acmicpc.net/problem/11050
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, k;	cin >> n >> k;
	vector<int> fac(n + 1);
	fac[0] = 1;
	fac[1] = 1;
	for (int i = 2; i <= n; i++)
		fac[i] = fac[i-1] * i;
	cout << fac[n] / fac[k] / fac[n-k];
}