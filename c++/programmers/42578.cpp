/*
 * 위장
 * https://programmers.co.kr/learn/courses/30/lessons/42578
 */

#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> hash;
	for (auto v : clothes) hash[v[1]]++;
	for (auto elem : hash) answer *= (elem.second + 1);
	return answer - 1;
}