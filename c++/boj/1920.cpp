/*
 * 수 찾기
 * https://www.acmicpc.net/problem/1920
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> a(n);
	for (int &elem : a) cin >> elem;
	map<int, int> hash;
	for (int elem : a) hash[elem]++;
	int m;	cin >> m;
	vector<int> b(m);
	for (int &elem : b) cin >> elem;
	for (int elem : b) {
		if (hash[elem]) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}