/*
 * 신입 사원
 * https://www.acmicpc.net/problem/1946
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// ❗️다른 모든 지원자와 비교했을 때 성적, 면접 둘 중 하나라도 높은 사람을 카운트하는 문제
int GREEDY(int n) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 1;
	vector<pair<int, int> > v;

	// 입력받는 부분
	for (int i = 0; i < n; i++) {
		int resume, interview;
		cin >> resume >> interview;
		v.push_back(make_pair(resume, interview));
	}
	// 서류성적순위로 오름차순 정렬
	sort(v.begin(), v.end());
	int val = v[0].second;
	// 인덱스가 뒤로 갈수록 서류성적순위는 낮을테니
	// 면접성적순위가 더 높은 면접자만 answer에 포함시키면서
	// 비교를 위한 val을 갱신
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
	int candidate;
	cin >> test_case;

	while (test_case--) {
		cin >> candidate;
		cout << GREEDY(candidate) << '\n';
	}
	return 0;
}