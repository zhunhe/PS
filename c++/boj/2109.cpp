/*
 * 순회강연
 * https://www.acmicpc.net/problem/2109
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<pair<int, int> > v;

int set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int p, d;
	int max_d = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back(make_pair(p, d));
		max_d = max(max_d, d);
	}
	return max_d;
}

bool compare(pair<int, int> front, pair<int, int> back) {
	if (front.second > back.second)
		return true;
	return false;
}

int solve_GREEDY(int max_d) {
	int money = 0;
	priority_queue<int> pq;
	sort(v.begin(), v.end(), compare);

	int i = 0;
	while (max_d > 0) {
		while (v[i].second == max_d) {
			pq.push(v[i].first);
			i++;
		}
		if (pq.size()) {
			money += pq.top();
			pq.pop();
		}
		max_d--;
	}
	return money;
}

int main() {
	int max_d;

	max_d = set_input_data();
	cout << solve_GREEDY(max_d);
	return 0;
}