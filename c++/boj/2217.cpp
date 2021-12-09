/*
 * 로프
 * https://www.acmicpc.net/problem/2217
 */

#include <iostream>
#include <algorithm>
using namespace std;

int rope[100001];

bool compare(int front, int back) {
	if (front > back)
		return true;
	return false;
}

// ❗️로프를 이용하여 들 수 있는 최대 무게를 구하는 문제
// 각 로프에는 w/k만큼의 중량이 걸리게 됨
int GREEDY(int n) {
	int max_value = 0;

	// 로프를 내림차순 정렬
	sort(rope, rope + n, compare);
	for (int i = 0; i < n; i++) {
		// 가장 적게 버틸 수 있는 로프 * 갯수로 최대값을 갱신
		max_value = max(max_value, rope[i] * (i + 1));
	}
	return max_value;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> rope[i];
	cout << GREEDY(n);
	return 0;
}