/*
 * 최소 회의실 개수
 * https://www.acmicpc.net/problem/19598
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;	cin >> n;
	vector<pair<int, int>> meeting(n);
	for (auto &elem : meeting) cin >> elem.first >> elem.second;
	sort(meeting.begin(), meeting.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(meeting[0].second);
	int m = 1;
	for (int i = 1; i < n; i++)	{
		while (pq.size() && pq.top() <= meeting[i].first) pq.pop();
		pq.push(meeting[i].second);
		m = max(m, (int)pq.size());
	}
	cout << m;
}