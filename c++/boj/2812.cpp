/*
 * 크게 만들기
 * https://www.acmicpc.net/problem/2812
 */

#include <bits/stdc++.h>
using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    string num;
    cin >> num;

    deque<char> dq;
    for (int i = 0; i < num.length(); i++) {
        while (K && dq.size() && num[i] > dq.back()) {
            dq.pop_back();
            K--;
        }
        dq.push_back(num[i]);
    }
    while (K) {
        dq.pop_back();
        K--;
    }

    while (dq.size()) {
        cout << dq.front();
        dq.pop_front();
    }
}