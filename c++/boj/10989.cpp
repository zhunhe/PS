/*
 * 수 정렬하기 3
 * https://www.acmicpc.net/problem/10989
 */

#include "bits/stdc++.h"
using namespace std;

int num[10001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;  cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;    cin >> tmp;
        num[tmp]++;
    }
    for (int i = 1; i < 10001; i++)
        while (num[i]--)
            cout << i << '\n';
}