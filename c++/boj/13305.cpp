/*
 * 주유소
 * https://www.acmicpc.net/problem/13305
 */

#include <bits/stdc++.h>
using namespace std;

int N;
long long DISTANCE[100001];
long long OIL[100001];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
		cin >> DISTANCE[i];
	for (int i = 0; i < N; i++)
		cin >> OIL[i];
}

// ❗️다음 마을까지의 거리, 주유소의 가격을 입력받아 이동에 필요한 최소금액을 구하는 문제
long long GREEDY() {
	long long answer = 0;
	long long price = OIL[0];

	for (int i = 0; i < N - 1; i++) {
		// 최소 주유가격을 갱신
		price = min(price, OIL[i]);
		// 다음 마을까지의 거리 * 오일가격을 answer에 더해줌
		answer += price * DISTANCE[i];
	}
	return answer;
}

int main() {
	set_input_data();
	cout << GREEDY();
}