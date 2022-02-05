/*
 * 수 정렬하기 4
 * https://www.acmicpc.net/problem/11931
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
    int n;  cin >> n;
    vector<int> num(n);
    for (int &elem : num) cin >> elem;
    sort(num.begin(), num.end(), [&](int front, int back){
        return front > back;
    });
    for (int elem : num) cout << elem << '\n';
}