/*
 * 쇠막대기
 * https://www.acmicpc.net/problem/10799
 */

#include <iostream>
using namespace std;

int ANSWER;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string brace;
    cin >> brace;

    int sum = 0;
    for (int i = 0; i < brace.length(); i++) {
        if (brace[i] == '(' && brace[i + 1] == ')') {
            ANSWER += sum;
            i++;
        } else if (brace[i] == '(') {
            sum++;
        } else if (brace[i] == ')') {
            sum--;
            ANSWER++;
        }
    }
    cout << ANSWER << endl;
    return 0;
}