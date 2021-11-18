/*
 * 가장 큰 정사각형
 * https://www.acmicpc.net/problem/1915
 */

#include <iostream>
using namespace std;

int N, M;
int DP[1001][1001];

int bsq() {
    int answer = 0;

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (DP[i][j] == 0) continue;
            int min = 0;
            if (DP[i - 1][j] > DP[i][j - 1])
                min = DP[i][j - 1];
            else
                min = DP[i - 1][j];
            if (min > DP[i - 1][j - 1])
                min = DP[i - 1][j - 1];
            DP[i][j] = min + 1;
            answer = max(answer, DP[i][j]);
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp.length(); j++) {
            DP[i][j] = tmp[j] - '0';
        }
    }
    int answer = bsq();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
    cout << answer * answer;
    return 0;
}