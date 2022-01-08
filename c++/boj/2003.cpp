/*
 * 수들의 합 2
 * https://www.acmicpc.net/problem/2003
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	vector<int> num(n);
	for (int &elem : num) cin >> elem;
	int ans = 0, sum = 0, left = 0;
	for (int i = 0; i < n; i++) {
		sum += num[i];
		while (sum >= m) {
			if (sum == m) ans++;
			sum -= num[left++];
		}
	}
	cout << ans;
}