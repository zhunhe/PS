/*
 * 동전1
 * https://www.acmicpc.net/problem/2293
 */

#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int COIN[101];
int dp[10001];

// set_input_data() is a function that stores data received as a standard input in a variable.
void set_input_data() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> COIN[i];
    }
}

// solve_DP() is a function that solves problem using dynamic programming technique.
// Coin change problem number of ways to get total
int DP() {
    dp[0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = COIN[i]; j <= K; j++) {
            dp[j] += dp[j - COIN[i]];
        }
    }
	return dp[K];
}

// main() is main function.
// set_input_data(): set data to 1-d array from standard input
// solve_DP(): solve problem using DP algorithm
int main() {
    set_input_data();
    cout << DP();
    return 0;
}