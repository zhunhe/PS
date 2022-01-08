/*
 * 내려가기
 * https://www.acmicpc.net/problem/2096
 */

#include "bits/stdc++.h"
using namespace std;

#define MAX(a)	*max_element(a.begin(), a.end())
#define MIN(a)	*min_element(a.begin(), a.end())

int main() {
	int n;	cin >> n;
	vector<int> score(3), dp_max(3), dp_min(3), tmp(3);
	for (int i = 0; i < n; i++) {
		cin >> score[0] >> score[1] >> score[2];
		tmp[0] = min(dp_min[0], dp_min[1]) + score[0];
		tmp[1] = min({dp_min[0], dp_min[1], dp_min[2]}) + score[1];
		tmp[2] = min(dp_min[1], dp_min[2]) + score[2];
		for (int i = 0; i < 3; i++)
			dp_min[i] = tmp[i];
		tmp[0] = max(dp_max[0], dp_max[1]) + score[0];
		tmp[1] = max({dp_max[0], dp_max[1], dp_max[2]}) + score[1];
		tmp[2] = max(dp_max[1], dp_max[2]) + score[2];
		for (int i = 0; i < 3; i++)
			dp_max[i] = tmp[i];
	}
	cout << MAX(dp_max) << ' ' << MIN(dp_min);
}