/*
 * 2×n 타일링
 * https://www.acmicpc.net/problem/11726
 */

#include "bits/stdc++.h"
using namespace std;
#define MOD		10007
int cache[1001];

int dp(int n) {
	if (cache[n] != -1) return cache[n];
	int &ret = cache[n];
	if (n <= 2) return ret = n;
	return ret = (dp(n - 1)  + dp(n - 2)) % MOD;
}

int main() {
	int n;	cin >> n;
	memset(cache, -1, sizeof(cache));
	cout << dp(n);
}