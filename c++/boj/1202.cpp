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

// 보석 무게, 가격의 데이터들과 가방이 견딜 수 있는 무게들을 입력받아
// 가방 하나당 보석을 넣었을 때 가치가 최대가 되는 가격을 구하는 문제
long long GREEDY() {
	int v_idx = 0;
	long long answer = 0;
	priority_queue<int> pq;

	// 보석의 무게를 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	// 가방이 견딜 수 있는 무게를 기준으로 오름차순 정렬
	sort(bag.begin(), bag.end());
	for (int i = 0; i < K; i++) {
		// i번째 가방에 담을 수 있는 보석의 가격을 max_heap에 push
		while (v_idx < N && v[v_idx].first <= bag[i])
			pq.push(v[v_idx++].second);
		// i번째 가방에 담을 수 있는 가장 가치가 높은 보석을 answer에 더해주고 pop
		if (pq.size()) {
			answer += pq.top();
			pq.pop();
		}
	}
	return answer;
}

int main() {
	set_input_data();
	cout << GREEDY() << '\n';
	return 0;
}
