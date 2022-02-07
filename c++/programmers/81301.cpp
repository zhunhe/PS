/*
 * 숫자 문자열과 영단어
 * https://programmers.co.kr/learn/courses/30/lessons/81301
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> number = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
	int answer = 0;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if ('0' <= s[i] && s[i] <= '9')
			answer = answer * 10 + s[i] - '0';
		else {
			tmp += s[i];
			for (int j = 0; j < number.size(); j++) {
				if (tmp == number[j]) {
					answer = answer * 10 + j;
					tmp = "";
					break;
				}
			} 
		}
	}
	return answer;
}

int main() {
	vector<string> s{
		"one4seveneight",
		"23four5six7",
		"2three45sixseven",
		"123"
	};
	vector<int> want{
		1478,
		234567,
		234567,
		123
	};
	for (int i = 0; i < want.size(); i++) {
		int got = solution(s[i]);
		cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}