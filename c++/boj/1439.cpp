/*
 * 뒤집기
 * https://www.acmicpc.net/problem/1439
 */

#include <iostream>
#include <string>
using namespace std;

string s;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> s;
}

// ❗️0, 1로 이루어진 문자열이 주어졌을 때 모두 같은 숫자로 만들기 위한 최소횟수
// 이어진 숫자들은 한 번에 바꿀 수 있음
int GREEDY() {
	int zero_cnt = 0;
	int one_cnt = 0;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		// 전체 s에서 이어진 0, 1의 개수를 카운트해줌
		if (i == 0 || s[i] != s[i - 1]) {
			if (s[i] == '0') zero_cnt++;
			else one_cnt++;
		}
	}
	// 카운트 해준 값 중 더 작은 값을 리턴
	return (zero_cnt >= one_cnt ? one_cnt : zero_cnt);
}

int main() {
	set_input_data();
	cout << GREEDY();
	return 0;
}