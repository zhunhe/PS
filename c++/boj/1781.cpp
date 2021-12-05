/*
 * 컵라면
 * https://www.acmicpc.net/problem/1781
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, long long> > v;
priority_queue<long long> pq;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int deadline;
	long long cup_lamen;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> deadline >> cup_lamen;
		v.push_back(make_pair(deadline, cup_lamen));
	}
}

bool compare(pair<int, long long> front, pair<int, long long> back) {
	if (front.first > back.first)
		return true;
	return false;
}

long long solve_GREEDY() {
	long long answer = 0;
	int i = 0;

	sort(v.begin(), v.end(), compare);
	int deadline_max = v[0].first;
	while (deadline_max) {
		while (v[i].first == deadline_max) {
			pq.push(v[i++].second);
		}
		if (pq.size()) {
			answer += pq.top();
			pq.pop();
		}
		deadline_max--;
	}
	return answer;
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
	return 0;
}