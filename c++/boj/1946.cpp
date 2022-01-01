/*
 * 신입 사원
 * https://www.acmicpc.net/problem/1946
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int n; cin >> n;
		int answer = 1;
		vector<pair<int, int> > v(n);
		for (auto &elem : v) cin >> elem.first >> elem.second;
		sort(v.begin(), v.end());
		int val = v[0].second;
		for (int i = 1; i < n; i++) {
			if (v[i].second < val) {
				answer++;
				val = v[i].second;
			}
		}
		cout << answer << '\n';
	}
}