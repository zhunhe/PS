/*
 * 수 정렬하기 2
 * https://www.acmicpc.net/problem/2751
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> num(n);
    for (int &elem : num) cin >> elem;
    sort(num.begin(), num.end());
    for (int elem : num) cout << elem << '\n';
}