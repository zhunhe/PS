/*
 * 게으른 백곰
 * https://www.acmicpc.net/problem/10025
 */

#include "bits/stdc++.h"
using namespace std;

#define MAX		1000 * 1000
int dist[MAX + 1];

int main() {
	int n, k, end, sum = 0, ans = 0;	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int amount, location;	cin >> amount >> location;
		dist[location] = amount;
		end = max(end, location);
	}
	if (k >= 500000) {
		for (int i = 0; i < MAX + 1; i++)
			sum += dist[i];
		cout << sum;
		return 0;
	}
	for (int i = 0; i < k * 2 + 1; i++)
		sum += dist[i];
	ans = sum;
	int left = 0;
	for (int right = k * 2 + 1; right < MAX + 1; right++) {
		sum += dist[right] - dist[left++];
		ans = max(ans, sum);
	}
	cout << ans;
}