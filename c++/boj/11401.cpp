/*
 * 이항 계수 3
 * https://www.acmicpc.net/problem/11401
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long   ll;
#define MOD 1000000007

ll fast_pow(ll base, ll exp) {
    ll ret = 1;
    while (exp) {
        if (exp % 2 == 1)
            ret = (ret * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ret;
}

int main() {
    ll n, k, fac_n = 1, fac_n_minus_k = 1, fac_k = 1;
    cin >> n >> k;
    for (int i = 1; i < n + 1; i++)
        fac_n = (fac_n * i) % MOD;
    for (int i = 1; i < n - k + 1; i++)
        fac_n_minus_k = (fac_n_minus_k * i) % MOD;
    for (int i = 1; i < k + 1; i++)
        fac_k = (fac_k * i) % MOD;
    cout << ((fac_n * fast_pow(fac_n_minus_k, MOD - 2) % MOD) * fast_pow(fac_k, MOD - 2)) % MOD;
}