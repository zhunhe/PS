/*
 * 수 정렬하기 5
 * https://www.acmicpc.net/problem/15688
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;  cin >> n;
    vector<int> num(n);
    for (int &elem : num) cin >> elem;
    sort(num.begin(), num.end());
    for (int elem : num) cout << elem << '\n';
}