/*
 * 뒤집기
 * https://www.acmicpc.net/problem/1439
 */

#include <iostream>
#include <string>
using namespace std;

string S;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> S;
}

int solve_GREEDY() {
	int zero_cnt = 0;
	int one_cnt = 0;
	int len = S.length();

	for (int i = 0; i < len; i++) {
		if (i == 0 || S[i] != S[i - 1]) {
			if (S[i] == '0') zero_cnt++;
			else one_cnt++;
		}
	}
	return (zero_cnt >= one_cnt ? one_cnt : zero_cnt);
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
	return 0;
}