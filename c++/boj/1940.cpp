/*
 * 주몽
 * https://www.acmicpc.net/problem/1940
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;	cin >> n >> m;
	vector<int> num(n);
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	int left = 0, right = num.size() - 1, ans = 0;
	while (left < right) {
		if (num[left] + num[right] == m) {
			ans++;
			left++;
			right--;
			continue;
		}
		if (num[left] + num[right] < m) left++;
		else right--;
	}
	cout << ans;
}
