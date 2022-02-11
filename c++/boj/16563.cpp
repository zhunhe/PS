/*
 * 어려운 소인수분해
 * https://www.acmicpc.net/problem/16563
 */

#include "bits/stdc++.h"
using namespace std;
#define MAX		5000001
int sp[MAX];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> p;
	for (int i = 2; i < MAX; i++) {
		if (!sp[i]) p.push_back(i);
		for (int j : p) {
			if (i * j >= MAX) break;
			sp[i * j] = j;
			if (i % j == 0) break;
		}
	}
	int n;	cin >> n;
	while (n--) {
		int num;	cin >> num;
		while (sp[num])
			cout << sp[num] << ' ', num /= sp[num];
		cout << num << '\n';
	}
}