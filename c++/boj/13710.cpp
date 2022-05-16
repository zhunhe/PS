/*
 * XOR 합 3
 * https://www.acmicpc.net/problem/13710
 */

#include "bits/stdc++.h"
using namespace std;

int64_t ans, cnt[30][2];

int main() {
	int n;	cin >> n;
	vector<int64_t> seq(n + 1), prefix(n + 1);
	for (int i = 1; i < n + 1; i++) {
		cin >> seq[i];
		prefix[i] = prefix[i - 1] ^ seq[i];
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < 30; j++) {
			++cnt[j][(bool)(prefix[i] & (1 << j))];
		}
	}
	for (int i = 0; i < 30; i++)
		ans += cnt[i][0] * cnt[i][1] * (1LL << i);
	cout << ans;
}