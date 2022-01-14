/*
 * 중복 빼고 정렬하기
 * https://www.acmicpc.net/problem/10867
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> num(n);
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	num.erase(unique(num.begin(), num.end()), num.end());
	for (int elem : num) cout << elem << ' ';
}