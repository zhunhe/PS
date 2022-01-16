/*
 * 직사각형에서 탈출
 * https://www.acmicpc.net/problem/1085
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int x, y, w, h;	cin >> x >> y >> w >> h;
	cout << min({x, y, w - x, h - y});
}