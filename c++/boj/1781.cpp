/*
 * 컵라면
 * https://www.acmicpc.net/problem/1781
 */

#include <bits/stdc++.h>
using namespace std;


bool compare(pair<int, long long> front, pair<int, long long> back) {
	if (front.first > back.first)
		return true;
	return false;
}

int main() {
	int n;	cin >> n;
	vector<pair<int, long long> > v(n);
	for (auto &elem : v) cin >> elem.first >> elem.second;
	sort(v.begin(), v.end(), compare);
	long long answer = 0;
	int i = 0;
	priority_queue<long long> pq;
	for (int deadline = v[0].first; deadline > 0; deadline--) {
		while (v[i].first == deadline) pq.push(v[i++].second);
		if (pq.size()) {
			answer += pq.top();
			pq.pop();
		}
	}
	cout << answer;
}