/*
 * 색종이 만들기
 * https://www.acmicpc.net/problem/2630
 */

#include <bits/stdc++.h>
using namespace std;

#define WHITE       0
#define BLUE        1

int board[130][130];
int w_cnt, b_cnt;

bool is_same_color(int y, int x, int len) {
    int check_value = board[y][x];
    for (int i = y; i < y + len; i++)
        for (int j = x; j < x + len; j++)
            if (check_value != board[i][j]) return false;
    return true;
}

void divide_and_conquer(int y, int x, int len) {
    if (is_same_color(y, x, len)) {
        if (board[y][x] == WHITE) w_cnt++;
        else b_cnt++;
        return ;
    }
    divide_and_conquer(y, x, len/2);
    divide_and_conquer(y, x + len/2, len/2);
    divide_and_conquer(y + len/2, x, len/2);
    divide_and_conquer(y + len/2, x + len/2, len/2);
}

int main() {
	int n;	cin >> n;
	for (int i = 0; i < n * n; i++) cin >> board[i / n][i % n];
    divide_and_conquer(0, 0, n);
    cout << w_cnt << "\n" << b_cnt;
}