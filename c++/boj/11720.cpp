/*
 * 숫자의 합
 * https://www.acmicpc.net/problem/11720
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, ans = 0;	cin >> n;
	for (int i = 0; i < n; i++) {
		char tmp;	cin >> tmp;
		ans += tmp - '0';
	}
	cout << ans;
}