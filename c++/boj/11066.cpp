/*
 * 파일 합치기
 * https://www.acmicpc.net/problem/11066
 */

#include <iostream>
#include <string.h>
using namespace std;

int N;
int cache[501][501];
int cost[501];
int preSum[501];

int dp(int a, int b) {
	if (a == b)
		return cost[a];
	int& ret = cache[a][b];
	if (ret != -1)
		return ret;

	ret = 1e9;
	int sum = preSum[b+1] - preSum[a];
	for (int i = a; i < b; i++) {
		ret = min(ret, dp(a, i) + dp(i + 1, b) + sum);
	}
	return ret;
}

int solve(int num) {
	int ret = 1e9;

	for (int i = 0; i < num - 1; i++) {
		ret = min(ret, dp(0, i) + dp(i + 1, num - 1));
	}
	return ret;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		memset(cache, -1, sizeof(cache));
		int num;

		cin >> num;
		for (int j = 0; j < num; j++)
			cin >> cost[j];
		for (int j = 1; j <= num; j++)
			preSum[j] = preSum[j - 1] + cost[j-1];
		cout << solve(num) << '\n';
	}
}