/*
 * 상자넣기
 * https://www.acmicpc.net/problem/1965
 */

#include <iostream>
using namespace std;
int N;
int BOX[1001];
int DP[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> BOX[i];
    }
    fill_n(DP, N, 1);
    for (int i = 1; i < N; i++) {
        int max = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (BOX[j] >= BOX[i]) continue;
            if (DP[j] <= max) continue;
            max = DP[j];
        }
        if (max != -1) {
            DP[i] = max + 1;
        }
    }
    int answer = -1;
    for (int i = 0; i < N; i++) {
        if (answer > DP[i]) continue;
        answer = DP[i];
    }
    cout << answer;
}