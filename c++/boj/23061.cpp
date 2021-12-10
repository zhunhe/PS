/*
 * 백남이의 여행 준비
 * https://www.acmicpc.net/problem/23061
 */

#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<pair<int, int> > v;
vector<int> bag;
int dp[101][1000001];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int weight, value;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> weight >> value;
		v.push_back(make_pair(weight, value));
	}
	for (int i = 0; i < m; i++) {
		cin >> weight;
		bag.push_back(weight);
		k = max(k, weight);
	}
}

int DP() {
	for (int i = 1; i <= n; i++) {
		const int weight = v[i - 1].first;
		const int value = v[i - 1].second;
		for (int j = 1; j <= k; j++) {
			if (j < weight)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
		}
	}
	int idx = 0;
	double efficiency = 0;
	for (int i = 0; i < m; i++) {
		if ((double)dp[n][bag[i]] / bag[i] > efficiency) {
			efficiency = (double)dp[n][bag[i]] / (double)bag[i];
			idx = i;
		}
	}
	return idx + 1;
}

int main() {
	set_input_data();
	cout << DP();
	return 0;
}