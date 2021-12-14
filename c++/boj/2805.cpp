/*
 * 나무 자르기
 * https://www.acmicpc.net/problem/2805
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long	ll;

int main() {
	FAST_IO();
	int n, m;	cin >> n >> m;
	vector<ll> log(n);
	for (int i = 0; i < n; i++) cin >> log[i];
	ll left = 1, right = *max_element(log.begin(), log.end());
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cut = 0;
		for (int i = 0; i < n; i++)
			cut += log[i] >= mid ? log[i] - mid : 0;
		if (cut >= m) {
			left = mid + 1;
			ans = mid;
		} else	right = mid - 1;
	}
	cout << ans;
}