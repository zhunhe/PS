/*
 * 나이순 정렬
 * https://www.acmicpc.net/problem/10814
 */

#include "bits/stdc++.h"
using namespace std;

struct mData {
    int age, order;
    string name;
};

int main() {
    int n;  cin >> n;
    vector<mData> member(n);
    for (int i = 0; i < n; i++) {
        cin >> member[i].age >> member[i].name;
        member[i].order = i;
    }
    sort(member.begin(), member.end(), [&](mData front, mData back){
        if (front.age == back.age)
            return front.order < back.order;
        return front.age < back.age;
    });
    for (mData elem : member) cout << elem.age << ' ' << elem.name << '\n';
}