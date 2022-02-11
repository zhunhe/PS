/*
 * 합이 0인 네 정수
 * https://www.acmicpc.net/problem/7453
 */

#include "bits/stdc++.h"
using namespace std;
long long ans;

int main() {
	int n;	cin >> n;
	vector<vector<int>> arr(n, vector<int>(4));
	for (vector<int> &v : arr) for (int &elem : v) cin >> elem;
	vector<int> v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			v.push_back(-(arr[i][0] + arr[j][1]));
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			auto lower = lower_bound(v.begin(), v.end(), arr[i][2] + arr[j][3]);
			auto upper = upper_bound(v.begin(), v.end(), arr[i][2] + arr[j][3]);
			ans += upper - lower;
		}
	}
	cout << ans;
}