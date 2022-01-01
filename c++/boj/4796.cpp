/*
 * 캠핑
 * https://www.acmicpc.net/problem/4796
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 1;
	while (1) {
		int l, p, v;	cin >> l >> p >> v;
		if (l == 0) return 0;
		cout << "Case " << n++ << ": " << v / p * l + min(l, v % p) << '\n';
	}
}