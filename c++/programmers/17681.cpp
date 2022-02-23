/*
 * 비밀지도
 * https://programmers.co.kr/learn/courses/30/lessons/17681
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	for (int i = 0; i < n; i++) {
		int tmp = arr1[i] | arr2[i];
		for (inat j = 0; j < n; j++)
			answer[i] += (tmp & 1 << (n - 1 - j) ? '#' : ' ');
	}
	return answer;
}