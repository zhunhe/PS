/*
 * 쿼드트리
 * https://www.acmicpc.net/problem/1992
 */

#include <bits/stdc++.h>
using namespace std;

int N;
int BOARD[66][66];
string ANSWER;

void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string tmp = "";

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            BOARD[i][j] = tmp[j] - '0';
        }
    }
}

bool check_same_color(int y, int x, int len) {
    int check_value = BOARD[y][x];

    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (BOARD[i][j] == check_value) continue;
            return false;
        }
    }
    return true;
}

void divide_and_conquer(int y, int x, int len) {
    if (check_same_color(y, x, len)) {
        ANSWER += to_string(BOARD[y][x]);
        return;
    }
    ANSWER += "(";
    divide_and_conquer(y, x, len/2);
    divide_and_conquer(y, x + len/2, len/2);
    divide_and_conquer(y + len/2, x, len/2);
    divide_and_conquer(y + len/2, x + len/2, len/2);
    ANSWER += ")";
}

int main() {
    set_input_data();
    divide_and_conquer(0, 0, N);
    cout << ANSWER;
}