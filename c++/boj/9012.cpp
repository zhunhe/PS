/*
 * 괄호
 * https://www.acmicpc.net/problem/9012
 */

#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
    cin >> T;
    while (T) {
        string brace;
        cin >> brace;

        int cnt = 0;
        bool flag = true;
        for (int i = 0; i < brace.length(); i++) {
            if (brace[i] == '(') {
                cnt++;
            }
            else {
                cnt--;
            }
            if (cnt < 0) {
                flag = false;
                break;
            }
        }
        if (flag && cnt == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        T--;
    }
}