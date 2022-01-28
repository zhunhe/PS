/*
 * 외판원 순회 3
 * https://www.acmicpc.net/problem/16991
 */

#include "bits/stdc++.h"
using namespace std;
#define INF		987654321
#define MAX_N	16
int n;
double dp[MAX_N][1<<MAX_N];
double graph[MAX_N][MAX_N];
struct coor {
	int y, x;
};

double tsp(int cur, int visited) {
	if (visited == (1 << n) - 1)
		return graph[cur][0] ? graph[cur][0] : INF;
	if (dp[cur][visited]) return dp[cur][visited];
	double &ret = dp[cur][visited];
	ret = INF;
	for (int next = 0; next < n; ++next)
		if (!(visited & (1 << next)) && graph[cur][next])
		ret = min(ret, graph[cur][next] + tsp(next, visited | (1 << next)));
	return ret;
}

int main() {
	cin >> n;
	vector<coor> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].y >> v[i].x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double tmp = sqrt(pow((v[i].y-v[j].y), 2.0) + pow((v[i].x-v[j].x), 2.0));
			graph[i][j] = graph[j][i] = tmp;
		}
	}
	printf("%lf", tsp(0, 1));
}