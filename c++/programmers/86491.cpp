/*
 * 최소직사각형
 * https://programmers.co.kr/learn/courses/30/lessons/86491
 */

#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<int>> sizes) {
	int longer = 0, shorter = 0;
	for (vector<int> elem : sizes) {
		if (elem[0] > elem[1]) {
			longer = max(longer, elem[0]);
			shorter = max(shorter, elem[1]);
		} else {
			longer = max(longer, elem[1]);
			shorter = max(shorter, elem[0]);
		}
	}
	return longer * shorter;
}

int main() {
	vector<vector<vector<int>>> sizes{
		{{60, 50}, {30, 70}, {60, 30}, {80, 40}},
		{{10, 7}, {12, 3}, {8, 15}, {14, 7}, {5, 15}},
		{{14, 4}, {19, 6}, {6, 16}, {18, 7}, {7, 11}}
	};
	vector<int> want{
		4000,
		120,
		133
	};
	for (int i = 0; i < want.size(); i++) {
		int got = solution(sizes[i]);
		cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}