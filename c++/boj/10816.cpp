/*
 * 숫자 카드 2
 * https://www.acmicpc.net/problem/10816
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, m;	cin >> n;
	vector<int> nums(n);
	for (int &elem : nums) cin >> elem;
	sort(nums.begin(), nums.end());
	cin >> m;
	vector<int> ans(m);
	for(int i = 0; i < m; i++) {
		cin >> n;
		ans[i] = upper_bound(nums.begin(), nums.end(), n) - lower_bound(nums.begin(), nums.end(), n);
	}
	for (int elem : ans) cout << elem << ' ';
}