/*
 * 숫자의 개수
 * https://www.acmicpc.net/problem/2577
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int a, b, c;	cin >> a >> b >> c;
	int ans = a * b * c;
	vector<int> count(10);
	while (ans) {
		count[ans % 10]++;
		ans /= 10;
	}
	for (int i = 0; i < 10; i++)
		cout << count[i] << '\n';
}