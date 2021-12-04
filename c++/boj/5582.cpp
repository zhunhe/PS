/*
 * 괄호
 * https://www.acmicpc.net/problem/5582
 */

#include <iostream>
#include <string>
using namespace std;

string S1;
string S2;
int S1_LEN;
int S2_LEN;
int DP[4002][4002];

// set_input_data() is a function that stores data received as a standard input in a variable.
void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S1;
    cin >> S2;
    S1 = " " + S1;
    S2 = " " + S2;
    S1_LEN = S1.length();
    S2_LEN = S2.length();
}

// solve_DP() is a function that solves problem using dynamic programming technique.
// LCS(Longest Common Substring) algorithm
int solve_DP() {
    int max_value = 0;
    for (int i = 1; i < S1_LEN; i++) {
        for (int j = 1; j < S2_LEN; j++) {
            if (S1[i] != S2[j]) continue;
            DP[i][j] = DP[i - 1][j - 1] + 1;
            max_value = max(max_value, DP[i][j]);
        }
    }
    return max_value;
}

// main() is main function.
// set_input_data(): set data to 2-d array from standard input
// solve_DP(): solve problem using DP(LCS) algorithm
int main() {
    set_input_data();
    cout << solve_DP();
    return 0;
}