/*
 * 최솟값 찾기
 * https://www.acmicpc.net/problem/11003
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;  cin >> n >> l;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int num;    cin >> num;
        pq.push({-num, i});
        while (pq.size() && pq.top().second + l <= i)
            pq.pop();
        cout << -pq.top().first << ' ';
    }
}