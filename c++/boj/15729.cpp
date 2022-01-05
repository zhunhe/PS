/*
 * 방탈출
 * https://www.acmicpc.net/problem/15729
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> light(n);
	for (int &elem : light) cin >> elem;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (light[i] == 0) continue;
		answer++;
		for (int j = 0; j < 3 && j < n; j++) light[i + j] ^= 1;
	}
	cout << answer;
}