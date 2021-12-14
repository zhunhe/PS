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

// ❗️문제의 데드라인과 해결시의 받을 수 있는 컵라면들의 정보가 있는 데이터를 받아
// 최대로 받을 수 있는 컵라면 수를 구하는 문제
long long GREEDY() {
	long long answer = 0;
	int i = 0;

	// 데드라인기준으로 내림차순 정렬
	sort(v.begin(), v.end(), compare);
	int deadline_max = v[0].first;
	while (deadline_max) {
		// 현재날짜와 데드라인이 같으면 max_heap에 push
		while (v[i].first == deadline_max) {
			pq.push(v[i++].second);
		}
		// 현재날짜중 가장 컵라면을 많이 받을 수 있는 문제를 선택
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
	cout << GREEDY();
}