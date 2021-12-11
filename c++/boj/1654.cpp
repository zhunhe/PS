/*
 * 랜선자르기
 * https://www.acmicpc.net/problem/1654
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int count(vector<int> line, int len) {
	int cnt = 0;
	for (int i = 0; i < line.size(); i++)
		cnt += line[i] / len;
	return cnt;
}

int main() {
	FAST_IO();
	int k, n; cin >> k >> n;
	vector<int> line(k);
	for (int i = 0; i < k; i++)	cin >> line[i];
	long left = 1;	long right = *max_element(line.begin(), line.end());
	long ans = 0;
	while (left <= right) {
		long mid = (left + right) / 2;
		if (count(line, mid) >= n) {
			ans = mid;
			left = mid + 1;
		} else
			right = mid - 1;
	}
	cout << ans << '\n';
	return 0;
}