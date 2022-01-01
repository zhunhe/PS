/*
 * 순회강연
 * https://www.acmicpc.net/problem/2109
 */

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> front, pair<int, int> back) {
	if (front.second > back.second)
		return true;
	return false;
}

int main() {
	int n;	cin >> n;
	vector<pair<int, int>> v(n);
	int day = 0;
	for (auto &elem : v) {
		cin >> elem.first >> elem.second;
		day = max(day, elem.second);
	}
	int money = 0;
	priority_queue<int> pq;
	sort(v.begin(), v.end(), compare);
	int i = 0;
	for (; day > 0; day--) {
		while (v[i].second == day) pq.push(v[i++].first);
		if (pq.size()) {
			money += pq.top();
			pq.pop();
		}
	}
	cout << money;
}