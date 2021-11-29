/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int COIN[101];
int DP[101];
int ANSWER;

int compare(int val1, int val2) {
    if (val1 > val2)
        return 1;
    return 0;
}

void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> COIN[i];
    }
}

void DFS(int L, int remain) {
    if (remain <= 0) {
        if (remain == 0) {
            ANSWER++;
        }
        return;
    }
    if (L == N - 1) {
        if (remain % COIN[L] == 0) {
            ANSWER++;
        }
        return;
    }
    for (int i = 0; COIN[L] * i <= remain; i++) {
        DFS(L + 1, remain - COIN[L] * i);
    }
}

int main() {
    set_input_data();
    sort(COIN, COIN + N, compare);
    DFS(0, K);
    cout << ANSWER;
    return 0;
}