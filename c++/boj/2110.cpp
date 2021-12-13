/*
 * 공유기 설치
 * https://www.acmicpc.net/problem/2110
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	FAST_IO();
	int n, c;	cin >> n >> c;
	vector<int> house(n);
	for (int i = 0; i < n; i++) cin >> house[i];
	sort(house.begin(), house.end());
	int left = 1; int right = house[house.size() - 1] - house[0];
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int point = house[0];
		for (int i = 0; i < house.size(); i++) {
			if (house[i] - point < mid) continue;
			cnt++;
			point = house[i];
		}
		if (cnt >= c) {
			if (ans < mid) ans = mid;
			left = mid + 1;
		} else right = mid - 1;
	}
	cout << ans;
}