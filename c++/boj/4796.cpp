/*
 * 캠핑
 * https://www.acmicpc.net/problem/4796
 */

#include <iostream>
using namespace std;

int main() {
	int l, p, v;
	int n = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0)
			return 0;
		cout << "Case " << n++ << ": " << v / p * l + min(l, v % p) << '\n';
	}
}