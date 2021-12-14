/*
 * 2048(Hard)
 * https://www.acmicpc.net/problem/12094
 */

#include <iostream>
using namespace std;

int ANSWER;
int N;

#define M           21
#define PRINT       0

void print_board(int **board) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << "Print Board !!" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void copy_board(int copy[M][M], int board[M][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            copy[i][j] = board[i][j];
        }
    }
}

int    up(int board[M][M]) {
#if PRINT
    cout << "@@@up@@@";
#endif
    int max = 0;

    for (int j = 0; j < N; j++) {
        int start = 0;
        for (int end = 0; end < N; end++) {
            if (board[start][j] == 0 && start < end) start++;
            if (board[end][j] == 0) continue;
            if (start < end && board[start][j] == board[end][j]) {
                board[start][j] *= 2;
                board[end][j] = 0;
                start = end + 1;
            } else if (board[end][j] != 0) {
                start = end;
            }
        }
        for (int i = 0; i < N; i++) {
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] != 0) continue;
            for (int k = i + 1; k < N; k++) {
                if (board[k][j] == 0) continue;
                board[i][j] = board[k][j];
                board[k][j] = 0;
                break;
            }                
        }
    }
#if PRINT
    print_board(board);
#endif
    return max;
}

int    down(int board[M][M]) {
#if PRINT
    cout << "@@@down@@@";
#endif
    int max = 0;

    for (int j = 0; j < N; j++) {
        int start = N - 1;
        for (int end = N - 1; end >= 0; end--) {
            if (board[start][j] == 0 && start > end) start--;
            if (board[end][j] == 0) continue;
            if (start > end && board[start][j] == board[end][j]) {
                board[start][j] *= 2;
                board[end][j] = 0;
                start = end - 1;
            } else if (board[end][j] != 0) {
                start = end;
            }
        }
        for (int i = N - 1; i >= 0; i--) {
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] != 0) continue;
            for (int k = i - 1; k >= 0; k--) {
                if (board[k][j] == 0) continue;
                board[i][j] = board[k][j];
                board[k][j] = 0;
                break;
            }                
        }
    }
#if PRINT
    print_board(board);
#endif
    return max;
}

int    left(int board[M][M]) {
#if PRINT
    cout << "@@@left@@@";
#endif
    int max = 0;

    for (int i = 0; i < N; i++) {
        int start = 0;
        for (int end = 0; end < N; end++) {
            if (board[i][start] == 0 && start < end) start++;
            if (board[i][end] == 0) continue;
            if (start < end && board[i][start] == board[i][end]) {
                board[i][start] *= 2;
                board[i][end] = 0;
                start = end + 1;
            } else if (board[i][end] != 0) {
                start = end;
            }
        }
        for (int j = 0; j < N; j++) {
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] != 0) continue;
            for (int k = j + 1; k < N; k++) {
                if (board[i][k] == 0) continue;
                board[i][j] = board[i][k];
                board[i][k] = 0;
                break;
            }
        }
    }
#if PRINT
    print_board(board);
#endif
    return max;
}

int    right(int board[M][M]) {
#if PRINT
    cout << "@@@right@@@";
#endif
    int max = 0;

    for (int i = 0; i < N; i++) {
        int start = N - 1;
        for (int end = N - 1; end >= 0; end--) {
            if (board[start] == 0 && start > end) start--;
            if (board[end] == 0) continue;
            if (start > end && board[i][start] == board[i][end]) {
                board[i][start] *= 2;
                board[i][end] = 0;
                start = end - 1;
            } else if (board[i][end] != 0) {
                start = end;
            }
        }
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] > max) max = board[i][j];
            if (board[i][j] != 0) continue;
            for (int k = j - 1; k >= 0; k--) {
                if (board[i][k] == 0) continue;
                board[i][j] = board[i][k];
                board[i][k] = 0;
                break;
            }
        }
    }
#if PRINT
    print_board(board);
#endif
    return max;
}

int get_max(int board[M][M]) {
    int max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > max) max = board[i][j];
        }
    }
    return max;
}

bool    is_same_array(int copy[M][M], int board[M][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (copy[i][j] != board[i][j]) return false;
        }
    }
    return true;
}

void DFS(int L, int board[M][M]) {
    int max;
    if (L == 10) {
        return;
    }
    int copy[M][M];
    copy_board(copy, board);

    max = up(copy);
    if (max > ANSWER) ANSWER = max;
    if (L > 0 && is_same_array(copy, board)) return;
    DFS(L + 1, copy);

    max = down(copy);
    if (max > ANSWER) ANSWER = max;
    if (L > 0 && is_same_array(copy, board)) return;
    DFS(L + 1, copy);

    max = left(copy);
    if (max > ANSWER) ANSWER = max;
    if (L > 0 && is_same_array(copy, board)) return;
    DFS(L + 1, copy);

    max = right(copy);
    if (max > ANSWER) ANSWER = max;
    if (L > 0 && is_same_array(copy, board)) return;
    DFS(L + 1, copy);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    int board[M][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    DFS(0, board);
    cout << ANSWER << endl;
}