/*
 * 신입 사원
 * https://www.acmicpc.net/problem/1946
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve_GREEDY(int n) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 1;
	vector<pair<int, int> > v;

	for (int i = 0; i < n; i++) {
		int resume, interview;
		cin >> resume >> interview;
		v.push_back(make_pair(resume, interview));
	}
	sort(v.begin(), v.end());
	int val = v[0].second;
	for (int i = 1; i < n; i++) {
		if (v[i].second < val) {
			answer++;
			val = v[i].second;
		}
	}
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_case;
	int cand;
	cin >> test_case;

	while (test_case--) {
		cin >> cand;
		cout << solve_GREEDY(cand) << '\n';
	}
	return 0;
}