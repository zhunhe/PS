/*
 * 회의실 배정
 * https://www.acmicpc.net/problem/1931
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int N;
vector<pair<int, int> > v;

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

int GREEDY() {
	stack<int> answer;

	// 회의를 💡종료시간 기준으로 오름차순 정렬
	sort(v.begin(), v.end(), compare);
	answer.push(v[0].second);
	for (int i = 1; i < N; i++) {
		// 다음 회의의 시작시간이 현재 회의 종료시간보다 작은 경우 회의를 진행할 수 없음
		if (v[i].first < answer.top()) continue;
		// 다음 회의의 시작시간이 크거나 같은 경우 다음 회의의 💡종료시간을 스택에 쌓음
		answer.push(v[i].second);
	}
	// 진행한 회의 갯수를 return
	return answer.size();
}

int main() {
    set_input_data();
	cout << GREEDY();
    return 0;
}