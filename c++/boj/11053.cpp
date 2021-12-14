/*
 * 가장 긴 증가하는 부분 수열
 * https://www.acmicpc.net/problem/11053
 */

#include <iostream>

using namespace std;
int N;
int A[1001];
int DP[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        DP[i] = 1;
    }
    for (int i = 0; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] >= A[i]) continue;
            if (DP[j] < DP[i]) continue;
            DP[i] = DP[j] + 1;
        }
    }
    int max = -1;
    for (int i = 0; i < N; i++) {
        if (max < DP[i])
            max = DP[i];
    }
    cout << max;
}