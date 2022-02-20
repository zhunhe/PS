/*
 * ATM
 * https://www.acmicpc.net/problem/11399
 */

#include "bits/stdc++.h"
using namespace std;
int answer, tmp;

int main() {
	int n;	cin >> n;
	vector<int> wTime(n);
	for (int &elem : wTime) cin >> elem;
	sort(wTime.begin(), wTime.end());
	for (int i = 0; i < n; i++) {
		tmp += wTime[i];
		answer += tmp;
	}
	cout << answer;
}