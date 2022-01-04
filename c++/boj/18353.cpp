/*
 * 병사 배치하기
 * https://www.acmicpc.net/problem/18353
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> str(n), dp(n, 1);
	for (int &elem : str) cin >> elem;
	for (int i = 1; i < n; i++)
		for (int j = 0; j < i; j++)
			if (str[i] < str[j])
				dp[i] = max(dp[i], dp[j] + 1);
    cout << n - *max_element(dp.begin(), dp.end());
}