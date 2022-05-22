/*
 * 보물
 * https://www.acmicpc.net/problem/1026
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, ans = 0;	cin >> n;
	vector<int> a(n), b(n);
	for (int &elem : a) cin >> elem;
	for (int &elem : b) cin >> elem;
	sort(a.begin(), a.end(), [&](int front, int back){
		return front > back;
	});
	sort(b.begin(), b.end());
	for (int i = 0; i < n; i++)
		ans += a[i] * b[i];
	cout << ans;
}