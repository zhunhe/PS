/*
 * 로프
 * https://www.acmicpc.net/problem/2217
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N[100001];

bool compare(int front, int back) {
	if (front > back)
		return true;
	return false;
}

int solve_GREEDY(int n) {
	int max_value = 0;

	sort(N, N+n, compare);
	for (int i = 0; i < n; i++) {
		max_value = max(max_value, N[i] * (i + 1));
	}
	return max_value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> N[i];
	cout << solve_GREEDY(n);
	return 0;
}