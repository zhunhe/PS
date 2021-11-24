/*
 * 색종이 만들기
 * https://www.acmicpc.net/problem/2630
 */

#include <iostream>
#include <vector>
using namespace std;

#define WHITE       0
#define BLUE        1

int BOARD[130][130];
int N;
int W_CNT;
int B_CNT;

void print_board() {
    cout << "PRINT BOARD!!\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << BOARD[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void set_board() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> BOARD[i][j];
        }
    }
}

bool check_board(int y, int x, int len) {
    int check_value = BOARD[y][x];

    for (int i = y; i < y + len; i++) {
        for (int j = x; j < x + len; j++) {
            if (check_value == BOARD[i][j]) continue;
            return false;
        }
    }
    return true;
}

void solution(int y, int x, int len) {
    if (check_board(y, x, len)) {
        if (BOARD[y][x] == WHITE) W_CNT++;
        else B_CNT++;
        return ;
    }
    solution(y, x, len/2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // 값 입력받기
    cin >> N;
    set_board();
    solution(0, 0, N);
    cout << W_CNT << "\n" << B_CNT;

    return 0;
}