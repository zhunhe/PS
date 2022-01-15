/*
 * 나머지
 * https://www.acmicpc.net/problem/3052
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	map<int, int> ans;
	for (int i = 0; i < 10; i++) {
		int tmp;	cin >> tmp;
		ans[tmp % 42]++;
	}
	cout << ans.size();
}