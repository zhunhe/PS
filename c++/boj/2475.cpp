/*
 * 검증수
 * https://www.acmicpc.net/problem/2475
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int ans = 0;
	for (int i = 0; i < 5; i++) {
		int tmp;	cin >> tmp;
		ans += (tmp * tmp);
	}
	cout << ans % 10;
}