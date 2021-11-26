/*
 * 색종이 만들기
 * https://www.acmicpc.net/problem/2630
 */

#include <iostream>
using namespace std;

#define WHITE       0
#define BLUE        1

int BOARD[130][130];
int N;
int W_CNT;
int B_CNT;

void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> BOARD[i][j];
        }
    }
}

// 해당 BOARD 범위에 있는 색이 모두 같은 색인지 확인
bool check_same_color(int y, int x, int len) {
    int check_value = BOARD[y][x];

    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (check_value == BOARD[i][j]) continue;
            return false;
        }
    }
    return true;
}

void divide_and_conquer(int y, int x, int len) {
    if (check_same_color(y, x, len)) {
        if (BOARD[y][x] == WHITE) W_CNT++;
        else B_CNT++;
        return ;
    }
    // 좌상
    divide_and_conquer(y, x, len/2);
    // 우상
    divide_and_conquer(y, x + len/2, len/2);
    // 좌하
    divide_and_conquer(y + len/2, x, len/2);
    // 우하
    divide_and_conquer(y + len/2, x + len/2, len/2);
}

int main() {
    set_input_data();
    divide_and_conquer(0, 0, N);
    cout << W_CNT << "\n" << B_CNT;
    return 0;
}