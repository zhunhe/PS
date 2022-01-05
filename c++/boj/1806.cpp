/*
 * 부분합
 * https://www.acmicpc.net/problem/1806
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, s;	cin >> n >> s;
	vector<int> num(n);
	for (int &elem : num) cin >> elem;
	int left = 0, sum = 0, ans = 1e9;
	for (int right = 0; right < n; right++) {
		sum += num[right];
		while (sum >= s) {
			ans = min(ans, right - left + 1);
			sum -= num[left++];
		}
	}
	cout << (ans == 1e9 ? 0 : ans);
}