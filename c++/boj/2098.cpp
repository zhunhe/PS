/*
 * 외판원 순회
 * https://www.acmicpc.net/problem/2098
 */

#include "bits/stdc++.h"
using namespace std;
#define INF		987654321
#define MAX_N	16
int n, Graph[MAX_N][MAX_N], dp[MAX_N][1 << MAX_N];

int tsp(int cur, int visited) {
	if (visited == (1 << n) - 1)
		return Graph[cur][0] ? Graph[cur][0] : INF;
	if (dp[cur][visited]) return dp[cur][visited];
	int &ret = dp[cur][visited];
	ret = INF;
	for (int next = 0; next < n; ++next)
		if (!(visited & (1 << next)) && Graph[cur][next])
			ret = min(ret, Graph[cur][next] + tsp(next, visited | (1 << next)));
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> Graph[i][j];
	cout << tsp(0, 1);
}
