/*
 * 주유소
 * https://www.acmicpc.net/problem/13305
 */

#include <iostream>
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

long long solve_GREEDY() {
	long long answer = 0;
	long long price = OIL[0];

	for (int i = 0; i < N - 1; i++) {
		price = min(price, OIL[i]);
		answer += price * DISTANCE[i];
	}
	return answer;
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
	return 0;
}