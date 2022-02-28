/*
 * 돌 게임
 * https://www.acmicpc.net/problem/9655
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	cout << (n & 1 ? "SK" : "CY");
}