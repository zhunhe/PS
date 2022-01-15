/*
 * 평균
 * https://www.acmicpc.net/problem/1546
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> score(n);
	for (int &elem : score) cin >> elem;
	int maxScore = *max_element(score.begin(), score.end());
	vector<double> newScore(n);
	for (int i = 0; i < n; i++)
		newScore[i] = score[i] * 100.0 / maxScore;
	double ans = 0;
	for (double elem : newScore)
		ans += elem;
	cout << ans / n;
}