/*
 * 상수
 * https://www.acmicpc.net/problem/2908
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	string a, b;	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a > b)
		cout << a;
	else
		cout << b;
}