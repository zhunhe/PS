/*
 * 연세워터파크
 * https://www.acmicpc.net/problem/15678
 */

#include "bits/stdc++.h"
using namespace std;
#define ll	long long
 
int main()
{
	int n, d;	cin >> n >> d;
	vector<ll> stone(n), dp(n);
	for (ll &elem : stone) cin >> elem;
	priority_queue<pair<ll, ll>> pq;
	pq.push({0, -1});
	for (int i = 0; i < n; i++)
	{
		dp[i] = stone[i];
		while (!pq.empty() && pq.top().second + d < i)
			pq.pop();
		dp[i] = max(dp[i], pq.top().first + stone[i]);
		pq.push({dp[i], i});
	}
	cout << *max_element(dp.begin(), dp.end());
}