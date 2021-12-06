/*
 * 보석 도둑
 * https://www.acmicpc.net/problem/1202
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, K;

vector<pair<int, int> > v;
vector<int> bag;
priority_queue<int> pq;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int mi, vi, ci;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> mi >> vi;
		v.push_back(make_pair(mi, vi));
	}
	for (int i = 0; i < K; i++) {
		cin >> ci;
		bag.push_back(ci);
	}
}

long long solve_GREEDY() {
	int v_idx = 0;
	long long answer = 0;

	sort(v.begin(), v.end());
	sort(bag.begin(), bag.end());
	for (int i = 0; i < K; i++) {
		while (v_idx < N && v[v_idx].first <= bag[i])
			pq.push(v[v_idx++].second);
		if (pq.size()) {
			answer += pq.top();
			pq.pop();
		}
	}
	return answer;
}

int main() {
	set_input_data();
	cout << solve_GREEDY() << '\n';
	return 0;
}
