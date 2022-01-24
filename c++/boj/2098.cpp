/*
 * 외판원 순회
 * https://www.acmicpc.net/problem/2098
 */

#include "bits/stdc++.h"
using namespace std;
#define MAX 1e9
int n;
vector<vector<int>> board;
int dp[16][1 << 16];

int tsp(int cur, int visited){
	if (dp[cur][visited]) return dp[cur][visited];
	if (visited == (1 << n) - 1)
	{
		if (board[cur][0] != 0)
			return board[cur][0];
		else
			return MAX;
	}
	int result = MAX;
	for (int i = 0; i < n; i++)
	{
		if (!((1 << i) & visited) && (board[cur][i] != 0))
			result = min(result, board[cur][i] + tsp(i, visited + (1 << i)));
	}
	dp[cur][visited] = result;
	return result;
}

int main() {
	cin >> n;
	board.resize(n, vector<int>(n));
	for (vector<int> &v : board) for (int &elem : v) cin >> elem;
	cout << tsp(0, 1);
}
