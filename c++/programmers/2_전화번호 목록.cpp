/*
 * 전화번호 목록
 * https://programmers.co.kr/learn/courses/30/lessons/42577
 */

#include <bits/stdc++.h>
using namespace std;

bool solution(vector<string> v) {
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 1; i++) {
		int len = v[i].size();
		if (v[i] == v[i+1].substr(0, len)) return false;
	}
	return true;
}