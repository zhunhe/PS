/*
 * 회의실 배정
 * https://www.acmicpc.net/problem/1931
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main() {
	FAST_IO();
	int n;	cin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)	cin >> v[i].second >> v[i].first;
	sort(v.begin(), v.end());
	stack<int> answer;
	answer.push(v[0].first);
	for (int i = 1; i < n; i++) {
		if (v[i].second < answer.top()) continue;
		answer.push(v[i].first);
	}
	cout << answer.size();
    return 0;
}