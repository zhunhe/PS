/*
 * 다트 게임
 * https://programmers.co.kr/learn/courses/30/lessons/17682
 */

#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
	int answer = 0, tmp = 0;
	vector<int> ret;
	for (int i = 0; i < s.size(); i++) {
		if (isdigit(s[i]))
			tmp = tmp * 10 + s[i] - '0';
		if (s[i] == 'D')
			tmp *= tmp;
		if (s[i] == 'T')
			tmp *= tmp * tmp;
		if (s[i] == '#')
			tmp *= -1;
		if (s[i] == '*')
		{
			tmp *= 2;
			if (!ret.empty())
				ret[ret.size() - 1] *= 2;
		}
		if (i + 1 == s.size() || (!isdigit(s[i]) && isdigit(s[i + 1])))
		{
			ret.push_back(tmp);
			tmp = 0;
		}
	}
	for (int elem : ret)
		answer += elem;
	return answer;
}