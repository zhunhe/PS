/*
 * 회의실 배정
 * https://www.acmicpc.net/problem/1931
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int> > v;
vector<int> answer;

bool compare(pair<int, int> v1, pair<int, int> v2) {
	if (v1.second == v2.second)
		return v1.first < v2.first;
	return v1.second < v2.second;
}

void set_input_data() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int start, end;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> start >> end;
		v.push_back(make_pair(start, end));
    }
}

void solve_GREEDY() {
	sort(v.begin(), v.end(), compare);
	answer.push_back(v[0].second);
	for (int i = 1; i < N; i++) {
		if (answer[answer.size() - 1] <= v[i].first) {
			answer.push_back(v[i].second);
		}
	}
}

int main() {
    set_input_data();
	solve_GREEDY();
	cout << answer.size();
    return 0;
}