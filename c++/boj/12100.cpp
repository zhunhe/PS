/*
 * 2048(Easy)
 * https://www.acmicpc.net/problem/12100
 */

#include <iostream>
using namespace std;

typedef long long ll;
ll N;
ll ANSWER;

ll **copy_board(ll **board) {
    ll **ret;

    ret = (ll **)malloc(sizeof(ll *) * N);
    for (int i = 0; i < N; i++) {
        ret[i] = (ll *)malloc(sizeof(ll) * N);
        for (int j = 0; j < N; j++) {
            ret[i][j] = board[i][j];
        }
    }
    return ret;
}

ll **up(ll **org) {
    ll **board = copy_board(org);

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
            if (board[i][j] != 0) continue;
            for (int k = i + 1; k < N; k++) {
                if (board[k][j] == 0) continue;
                board[i][j] = board[k][j];
                board[k][j] = 0;
                break;
            }                
        }
    }
    return board;
}

ll **down(ll **org) {
    ll **board = copy_board(org);

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
            if (board[i][j] != 0) continue;
            for (int k = i - 1; k >= 0; k--) {
                if (board[k][j] == 0) continue;
                board[i][j] = board[k][j];
                board[k][j] = 0;
                break;
            }                
        }
    }
    return board;
}

ll **left(ll **org) {
    ll **board = copy_board(org);

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
            if (board[i][j] != 0) continue;
            for (int k = j + 1; k < N; k++) {
                if (board[i][k] == 0) continue;
                board[i][j] = board[i][k];
                board[i][k] = 0;
                break;
            }
        }
    }
    return board;
}

ll **right(ll **org) {
    ll **board = copy_board(org);

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
            if (board[i][j] != 0) continue;
            for (int k = j - 1; k >= 0; k--) {
                if (board[i][k] == 0) continue;
                board[i][j] = board[i][k];
                board[i][k] = 0;
                break;
            }
        }
    }
    return board;
}

ll get_max(ll **board) {
    ll max = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] > max) max = board[i][j];
        }
    }
    return max;
}

void DFS(int L, ll **board) {
    if (L == 5) {
        ll max = get_max(board);
        if (max > ANSWER) ANSWER = max;
        return;
    }
    DFS(L + 1, up(board));
    DFS(L + 1, down(board));
    DFS(L + 1, left(board));
    DFS(L + 1, right(board));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    ll **board;
    board = (ll **)malloc(sizeof(ll *) * N);
    for (int i = 0; i < N; i++) {
        board[i] = (ll *)malloc(sizeof(ll) * N);
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
    DFS(0, board);
    cout << ANSWER << endl;
}