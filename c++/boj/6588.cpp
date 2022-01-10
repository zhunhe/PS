/*
 * 골드바흐의 추측
 * https://www.acmicpc.net/problem/6588
 */

#include "bits/stdc++.h"
using namespace std;

#define MAX		1000000

int main() {
	ios::sync_with_stdio(0);
	vector<bool> prime(MAX+1, true);
	for (int i = 2; i * i <= MAX; i++)
		if (prime[i])
			for (int j = i * i; j <= MAX; j += i)
				prime[j] = false;
	while (1) {
		int n;	cin >> n;
		if (n == 0) return 0;
		for (int i = 3; i / 2 <= n; i += 2) {
			if (!prime[i] || !prime[n - i]) continue;
			printf("%d = %d + %d\n", n, i, n - i);
			break;
		}
	}
}