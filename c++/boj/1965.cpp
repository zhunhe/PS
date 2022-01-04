/*
 * 상자넣기
 * https://www.acmicpc.net/problem/1965
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> box(n), dp(n, 1);
	for (int &elem : box) cin >> elem;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (box[j] >= box[i]) continue;
			dp[i] = max(dp[i], dp[j] + 1);
		}
	}
	cout << *max_element(dp.begin(), dp.end());
}