/*
 * 보석 쇼핑
 * https://programmers.co.kr/learn/courses/30/lessons/67258
 */

#include "bits/stdc++.h"
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    set<string> set_gems(gems.begin(), gems.end());
    map<string, int> map_gems;
    int left = 0, ans = 987654321;
    for (int right = 0; right < gems.size(); right++) {
        map_gems[gems[right]]++;
        while (map_gems.size() == set_gems.size()) {
            map_gems[gems[left]]--;
            if (map_gems[gems[left]] == 0)
                map_gems.erase(gems[left]);
            if (right - left + 1 < ans) {
                ans = right - left + 1;
                answer[0] = left + 1, answer[1] = right + 1;
            }
            left++;
        }
    }
    return answer;
}

int main() {
	vector<vector<string>> gems{
		{"DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"},
		{"AA", "AB", "AC", "AA", "AC"},
		{"XYZ", "XYZ", "XYZ"},
		{"ZZZ", "YYY", "NNNN", "YYY", "BBB"}
	};
	vector<vector<int>> want{
		{3, 7},
		{1, 3},
		{1, 1},
		{1, 5}
	};
	for (int i = 0; i < want.size(); i++) {
		vector<int> got = solution(gems[i]);
		cout << "TEST" << i + 1<< "\n";
		cout << "got: ";
		for (int j = 0; j < got.size(); j++)
			printf("%d ", got[j]);
		cout << "want: ";
		for (int j = 0; j < want[i].size(); j++)
			printf("%d ", want[i][j]);
		cout << '\n';
		// cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}