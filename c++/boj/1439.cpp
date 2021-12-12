/*
 * 뒤집기
 * https://www.acmicpc.net/problem/1439
 */

#define FAST_IO() std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
#include <iostream>
using namespace std;

int main() {
	FAST_IO();
	string s;	cin >> s;
	int zero_cnt = 0;	int one_cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			if (s[i] == '0') zero_cnt++;
			else if (s[i] == '1') one_cnt++;
		}
	}
	cout << (zero_cnt >= one_cnt ? one_cnt : zero_cnt);
	return 0;
}