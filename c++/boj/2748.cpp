/*
 * 피보나치 수 2
 * https://www.acmicpc.net/problem/2748
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<long long> fibo(n+1);
	fibo[1] = 1;
	for (int i = 2; i <= n; i++)
		fibo[i] = fibo[i-2] + fibo[i-1];
	cout << fibo[n];
}