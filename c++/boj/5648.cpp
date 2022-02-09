/*
 * 역원소 정렬
 * https://www.acmicpc.net/problem/5648
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;	cin >> n;
	vector<long long> v;
	for (int i = 0; i < n; i++) {
		string tmp;	cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		v.push_back(stoll(tmp));
	}
	sort(v.begin(), v.end());
	for (long long elem : v) cout << elem << '\n';
}