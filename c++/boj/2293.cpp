/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int COIN[101];
int DP[10001];

void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> COIN[i];
    }
}

void solve_DP() {
    DP[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = COIN[i]; j <= K; j++) {
            DP[j] += DP[j - COIN[i]];
        }
    }
}

int main() {
    set_input_data();
    solve_DP();
    cout << DP[K];
    return 0;
}