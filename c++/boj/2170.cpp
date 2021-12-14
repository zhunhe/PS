/*
 * 선 긋기
 * https://www.acmicpc.net/problem/2170
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int> > v;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int from, to;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> from >> to;
		v.push_back(make_pair(from, to));
	}
}

// ❗️선들의 시작, 끝 좌표롤 입력받아 겹치는 부분을 제외한 총 길이를 구하는 문제
int GREEDY() {
	// 입력받은 시작, 끝 좌표의 겹치는 부분을 합쳐서 answer에 저장
	vector<pair<int, int> > answer;

	// 시작위치를 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	answer.push_back(make_pair(v[0].first, v[0].second));
	for (int i = 1; i < n; i++) {
		bool overlapped = false;
		for (int j = 0; j < answer.size(); j++) {
			// 겹치지 않는 경우 continue
			if (v[i].second < answer[j].first) continue;
			if (answer[j].second < v[i].first) continue;
			answer[j].second = max(answer[j].second, v[i].second);
			answer[j].first = min(answer[j].first, v[i].first);
			overlapped = true;
			break;
		}
		// 겹치는 선이 하나도 없는 경우 새로 push 해줌
		if (!overlapped)
			answer.push_back(make_pair(v[i].first, v[i].second));
	}
	// 선의 총 길이를 계산
	int length = 0;
	for (int i = 0; i < answer.size(); i++) {
		length += (answer[i].second - answer[i].first);
	}
	return length;
}

int main() {
	set_input_data();
	cout << GREEDY();
}