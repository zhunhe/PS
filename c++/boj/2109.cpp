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

// ❗️강연료, 데드라인의 데이터들을 입력받아 가장 많이 벌 수 있는 금액을 구하는 문제
int GREEDY(int max_d) {
	int money = 0;
	priority_queue<int> pq;
	// 강연데이터를 날짜 기준으로 내림차순 정렬
	sort(v.begin(), v.end(), compare);

	int i = 0;
	// 마지막날부터 첫번째날까지 반복
	while (max_d > 0) {
		// 현재날짜가 강연날짜와 같은 경우 max_heap에 강연료를 push
		while (v[i].second == max_d) {
			pq.push(v[i].first);
			i++;
		}
		// 가장 강연료가 비싼 강연부터 하루에 하나씩 진행
		if (pq.size()) {
			money += pq.top();
			pq.pop();
		}
		max_d--;
	}
	// 강연료의 합을 리턴
	return money;
}

int main() {
	int max_d;

	max_d = set_input_data();
	cout << GREEDY(max_d);
}