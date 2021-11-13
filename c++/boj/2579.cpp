/*
 * 계단 오르기
 * https://www.acmicpc.net/problem/2579
 */

#include <iostream>

using namespace std;
int N;
int STAIR[301];
int DP[301];

int Max(int val1, int val2) {
    return val1 > val2 ? val1 : val2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> STAIR[i];
    }
    fill_n(DP, N, 1);

    DP[0] = STAIR[0];
    DP[1] = STAIR[0] + STAIR[1];
    DP[2] = Max(STAIR[0] + STAIR[2], STAIR[1] + STAIR[2]);
    for (int i = 3; i < N; i++) {
        DP[i] = Max(DP[i - 2] + STAIR[i], STAIR[i - 1] + STAIR[i] + DP[i - 3]);
    }
    cout << DP[N - 1];
    return 0;
}