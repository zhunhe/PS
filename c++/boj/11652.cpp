/*
 * 카드
 * https://www.acmicpc.net/problem/11652
 */

#include "bits/stdc++.h"
using namespace std;
int most;

int main() {
	int n;	cin >> n;
	map<long long, int> h;
	while (n--) {
		long long tmp;	cin >> tmp;
		h[tmp]++;
		most = max(most, h[tmp]);
	}
	for (auto elem : h) {
		if (elem.second != most) continue;
		cout << elem.first;
		break;
	}
}