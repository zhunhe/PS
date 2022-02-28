/*
 * 두 수의 합
 * https://www.acmicpc.net/problem/3273
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> nums(n);
	for (int &elem : nums) cin >> elem;
	int x;	cin >> x;
	map<int, int> count;
	int ans = 0;
	for (int elem : nums) {
		ans += count[x - elem];
		count[elem]++;
	}
	cout << ans;
}