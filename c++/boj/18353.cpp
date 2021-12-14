/*
 * 병사 배치하기
 * https://www.acmicpc.net/problem/18353
 */

#include <iostream>
using namespace std;

int N;
int STR[2001];
int DP[2001];

// set_input_data() is a function that stores data received as a standard input in a variable.
void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> STR[i];
    }
    fill_n(DP, N, 1);
}

// Solve_DP() is a function that solves problem using dynamic programming technique.
// LIS(Longest Increasing Subsequence) algorithm.
void solve_DP() {
    for (int i = 1; i < N; i++) {
        int max = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (STR[j] <= STR[i]) continue;
            if (DP[j] <= max) continue;
            max = DP[j];
        }
        if (max != -1)
            DP[i] = max + 1;
    }
}

// find_answer() is a function that finds answer from DP array.
int find_answer() {
    int answer = -1;
    for (int i = 0; i < N; i++) {
        if (answer > DP[i]) continue;
        answer = DP[i];
    }
    return N - answer;
}

// main() is main function.
// set_input_data(): set data to 1-d array from standard input
// solve_DP(): solve problem using DP(LIS) algorithm
// find_answer(): Find answer from DP table
int main() {
    set_input_data();
    solve_DP();
    cout << find_answer();
}