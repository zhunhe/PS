/*
 * 별 찍기 - 10
 * https://www.acmicpc.net/problem/2447
 */

#include <iostream>
using namespace std;

int N;
int VISIT[2200][2200];

void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
}

void divide_and_conquer(int y, int x, int len) {
    if (len == 1) {
        VISIT[y][x] = true;
        return;
    }
    // 좌상
    divide_and_conquer(y, x, len/3);
    // 상
    divide_and_conquer(y, x + len/3, len/3);
    // 우상
    divide_and_conquer(y, x + len/3 * 2, len/3);
    // 좌
    divide_and_conquer(y + len/3, x, len/3);
    // 우
    divide_and_conquer(y + len/3, x + len/3 * 2, len/3);
    // 좌하
    divide_and_conquer(y + len/3 * 2, x, len/3);
    // 하
    divide_and_conquer(y + len/3 * 2, x + len/3, len/3);
    // 우하
    divide_and_conquer(y + len/3 * 2, x + len/3 * 2, len/3);
}

int main() {
    set_input_data();
    divide_and_conquer(0, 0, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (VISIT[i][j]) {
                cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}