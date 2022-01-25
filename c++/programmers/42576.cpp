/*
 * 완주하지 못한 선수
 * https://programmers.co.kr/learn/courses/30/lessons/42576
 */

#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> hash;
	for (auto elem : completion)
		hash[elem]++;
	for (auto elem : participant) {
		if (hash[elem]--) continue;
		answer = elem;
	}
	return answer;
}

int main() {
	vector<vector<string>> participant{
		{"leo", "kiki", "eden"},
		{"marina", "josipa", "nikola", "vinko", "filipa"},
		{"mislav", "stanko", "mislav", "ana"}
	};
	vector<vector<string>> completion{
		{"eden", "kiki"},
		{"josipa", "filipa", "marina", "nikola"},
		{"stanko", "ana", "mislav"}
	};
	vector<string> want{
		"leo",
		"vinko",
		"mislav"
	};
	for (int i = 0; i < want.size(); i++) {
		string got = solution(participant[i], completion[i]);
		cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}