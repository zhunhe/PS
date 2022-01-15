/*
 * 막대기
 * https://www.acmicpc.net/problem/1094
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	int bitNumber = 0;
	while (n) {
		if (n & 1) bitNumber++;
		n >>= 1;
	}
	cout << bitNumber;
}