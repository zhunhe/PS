/*
 * 캠핑
 * https://www.acmicpc.net/problem/4796
 */

#include <iostream>
using namespace std;

// ❗v일짜리 휴가 중에 연속하는 p일 중 l일만 캠핑장을 사용할 수 있을 때
// 최대로 이용할 수 있는 날짜를 구하는 문제
int main() {
	int l, p, v;
	int n = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0)
			return 0;
		// 연속하는 p일 중 캠핑장을 최대로 이용할 수 있는 횟수 v / p와 l을 곱한 후
		// 나머지에 해당하는 v % p와 l 중 더 작은 값을 더해줌
		cout << "Case " << n++ << ": " << v / p * l + min(l, v % p) << '\n';
	}
}