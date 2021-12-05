/*
 * 방탈출
 * https://www.acmicpc.net/problem/15729
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int LIGHT[1000000];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> LIGHT[i];
	}
}

int solve_GREEDY() {
	int answer = 0;

	for (int i = 0; i < N; i++) {
		if (LIGHT[i] == 0) continue;
		answer++;
		for (int j = 0; j < 3 && j < N; j++) {
			if (LIGHT[i + j] == 1)
				LIGHT[i + j] = 0;
			else
				LIGHT[i + j] = 1;
		}
	}
	return answer;
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
	return 0;
}