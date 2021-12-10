/*
 * 평범한 배낭
 * https://www.acmicpc.net/problem/12865
 */

#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<pair<int, int> > v;
int dp[101][100001];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int weight, value;

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> weight >> value;
		v.push_back(make_pair(weight, value));
	}
}

int DP() {
	for (int i = 1; i <= n; i++) {
		const int weight = v[i - 1].first;
		const int price = v[i - 1].second;
		for (int j = 1; j <= k; j++) {
			if (j < weight) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + price);
		}
	}
	return dp[n][k];
}

int main() {
	set_input_data();
	cout << DP();
	return 0;
}