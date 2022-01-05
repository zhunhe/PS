/*
 * 주유소
 * https://www.acmicpc.net/problem/13305
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long	ll;

int main() {
	int n;	cin >> n;
	vector<ll> dist(n-1), oil(n);
	for (ll &elem : dist) cin >> elem;
	for (ll &elem : oil) cin >> elem;
	ll ans = 0, price = oil[0];
	for (int i = 0; i < n - 1; i++) {
		price = min(price, oil[i]);
		ans += price * dist[i];
	}
	cout << ans;
}