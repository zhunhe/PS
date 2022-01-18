/*
 * 피보나치 함수
 * https://www.acmicpc.net/problem/1003
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int t;	cin >> t;
	while (t--) {
		int n;	cin >> n;
		vector<int> zeroCount(n + 1);
		vector<int> oneCount(n + 1);
		zeroCount[0] = 1;
		zeroCount[1] = 0;
		oneCount[0] = 0;
		oneCount[1] = 1;
		for (int i = 2; i < n + 1; i++) {
			zeroCount[i] = zeroCount[i - 1] + zeroCount[i - 2];
			oneCount[i] = oneCount[i - 1] + oneCount[i - 2];
		}
		cout << zeroCount[n] << ' ' << oneCount[n] << '\n';
	}
}