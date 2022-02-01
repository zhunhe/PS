/*
 * 트럭
 * https://www.acmicpc.net/problem/13335
 */

#include "bits/stdc++.h"
using namespace std;

int n, w, L, t, cur_weight;
int truck[1002];

int main() {
    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) cin >> truck[i];
    queue<int> bridge;
    for (int i = 0; i < n; i++) {
        while (1) {
            if (bridge.size() == w) {
                cur_weight -= bridge.front();
                bridge.pop();
            }
            if (cur_weight + truck[i] <= L) break;
            bridge.push(0);
            t++;
        }
        bridge.push(truck[i]);
        cur_weight += truck[i];
        t++;
    }
    cout << t + w;
}