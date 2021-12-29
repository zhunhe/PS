/*
 * 최소 회의실 개수
 * https://www.acmicpc.net/problem/19598
 */

#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > v;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
}

// ❗️진행할 회의의 시작시간, 종료시간을 받아서 최소로 사용할 회의실의 갯수를 구하는 문제
int GREEDY() {
	// 💡min heap 우선순위큐 사용
	// 현재 진행중인 회의 중 가장 먼저 끝나는 회의를 다음 회의 시작시간을 비교하기 위함
	priority_queue<int, vector<int>, greater<int> > pq;

	// 회의를 💡시작시간 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	// 우선순위큐에 첫번째 회의의 종료시간을 push
	pq.push(v[0].second);
	int m = 1;
	for (int i = 1; i < n; i++)	{
		// 현재 진행중인 회의가 있는 경우 가장 먼저 끝나는 회의와 다음 회의의 시작시간을 비교하고
		// (진행중인 회의 중 가장 빨리 끝나는 회의의 종료시간 < 다음 회의의 시작시간)인 경우
		// 회의실을 그대로 사용(pop 후 push)
		while (!pq.empty() && pq.top() <= v[i].first)
			pq.pop();
		// 현재 진행중인 회의가 끝나지 않았으면 새로운 회의실을 사용(push)
		pq.push(v[i].second);
		// 사용하고 있는 회의실의 최대갯수를 갱신
		m = max(m, (int)pq.size());
	}
	return m;
}

int main() {
	set_input_data();
	cout << GREEDY();
}