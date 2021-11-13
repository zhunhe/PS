/*
 * 병사 배치하기
 * https://www.acmicpc.net/problem/18353
 */

#include <iostream>

using namespace std;
int N;
int STR[2001];
int DP[2001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> STR[i];
    }
    fill_n(DP, N, 1);
    for (int i = 1; i < N; i++) {
        int max = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (STR[j] <= STR[i]) continue;
            if (DP[j] <= max) continue;
            max = DP[j];
        }
        if (max != -1)
            DP[i] = max + 1;
    }
    int answer = -1;
    for (int i = 0; i < N; i++) {
        if (answer > DP[i]) continue;
        answer = DP[i];
    }
    cout << N - answer;
    return 0;
}