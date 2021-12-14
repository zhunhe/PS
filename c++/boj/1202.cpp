/*
 * 보석 도둑
 * https://www.acmicpc.net/problem/1202
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	FAST_IO();
	int n, k; cin >> n >> k;
	vector<pair<int, int> > gem(n);
	for (int i = 0; i < n; i++)	cin >> gem[i].first >> gem[i].second;
	vector<int> bag(k);
	for (int i = 0; i < k; i++)	cin >> bag[i];
	int v_idx = 0;
	long long answer = 0;
	priority_queue<int> pq;
	sort(gem.begin(), gem.end());
	sort(bag.begin(), bag.end());
	for (int i = 0; i < k; i++) {
		while (v_idx < n && gem[v_idx].first <= bag[i])
			pq.push(gem[v_idx++].second);
		if (pq.empty()) continue;
		answer += pq.top();
		pq.pop();
	}
	cout << answer;
}
