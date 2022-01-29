/*
 * 숫자 카드
 * https://www.acmicpc.net/problem/10815
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> nums(n);
	for (int &elem : nums) cin >> elem;
	sort(nums.begin(), nums.end());
	cin >> n;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int num;	cin >> num;
		ans[i] = (*lower_bound(nums.begin(), nums.end(), num) == num ? 1 : 0);
	}
	for (int elem : ans) cout << elem << ' ';
}
