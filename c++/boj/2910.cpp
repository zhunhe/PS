/*
 * 빈도 정렬
 * https://www.acmicpc.net/problem/2910
 */

#include "bits/stdc++.h"
using namespace std;
struct vData {
	int num, frequency;
};

int main() {
	int n, c, tmp;	cin >> n >> c;
	map<int, int> frequency, order;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		frequency[tmp]++;
		if (order[tmp] == 0) order[tmp] = i + 1;
	}
	vector<vData> v;
	for (auto elem : frequency)
		v.push_back({elem.first, elem.second});
	sort(v.begin(), v.end(), [&](vData front, vData back){
		if (front.frequency == back.frequency)
			return order[front.num] < order[back.num];
		return front.frequency > back.frequency;
	});
	for (vData elem : v)
		while (elem.frequency--)
			cout << elem.num << ' ';
}