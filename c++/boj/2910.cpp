/*
 * 빈도 정렬
 * https://www.acmicpc.net/problem/2910
 */

#include "bits/stdc++.h"
using namespace std;

map<int, int> order;

bool compare(pair<int, int> a, pair<int, int> b){
	if (a.second == b.second)
		return (order[a.first] < order[b.first]);
	return (a.second > b.second);
};

int main() {
	int n, c, tmp;	cin >> n >> c;
	map<int, int> hash;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		hash[tmp]++;
		if (order[tmp] == 0) order[tmp] = i + 1;
	}
	vector<pair<int, int>> v;
	for (auto elem : hash)
		v.push_back({elem.first, elem.second});
	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].second; j++)
			cout << v[i].first << ' ';
}