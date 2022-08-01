/*
 * 모의고사
 * https://school.programmers.co.kr/learn/courses/30/lessons/42840
 */


#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer(4);
    vector<int> one = {1, 2, 3, 4, 5};
    vector<int> two = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == one[i % one.size()])
            answer[1]++;
        if (answers[i] == two[i % two.size()])
            answer[2]++;
        if (answers[i] == three[i % three.size()])
            answer[3]++;
    }
    vector<int> ret;
    for (int i = 1; i < 4; i++) {
        if (ret.empty())
            ret.push_back(i);
        else if (answer[ret[ret.size() - 1]] == answer[i])
            ret.push_back(i);
        else if (answer[ret[ret.size() - 1]] < answer[i]) {
            ret.clear();
            ret.push_back(i);
        }
    }
    return ret;
}
