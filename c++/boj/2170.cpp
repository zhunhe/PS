/*
 * 선 긋기
 * https://www.acmicpc.net/problem/2170
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
vector<pair<int, int> > answer;

bool compare(pair<int, int> front, pair<int, int> back) {
	if (front.first == back.first)
		return (front.second < back.second);
	else
		return (front.first < back.first);
}

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int from, to;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> from >> to;
		v.push_back(make_pair(from, to));
	}
}

void solve_GREEDY() {
	sort(v.begin(), v.end(), compare);
	answer.push_back(make_pair(v[0].first, v[0].second));
	for (int i = 1; i < N; i++) {
		const int len = answer.size();
		bool flag = true;
		for (int j = 0; j < len; j++) {
			if (v[i].second < answer[j].first) continue;
			if (answer[j].second < v[i].first) continue;
			answer[j].second = max(answer[j].second, v[i].second);
			answer[j].first = min(answer[j].first, v[i].first);
			flag = false;
			break;
		}
		if (flag)
			answer.push_back(make_pair(v[i].first, v[i].second));
	}
}

int get_len() {
	int result = 0;
	for (int i = 0; i < answer.size(); i++) {
		result += (answer[i].second - answer[i].first);
	}
	return result;
}

int main() {
	set_input_data();
	solve_GREEDY();
	cout << get_len();
	return 0;
}