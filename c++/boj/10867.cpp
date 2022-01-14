/*
 * 중복 빼고 정렬하기
 * https://www.acmicpc.net/problem/10867
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> num(n), ans;
	for (int &elem : num) cin >> elem;
	sort(num.begin(), num.end());
	for (int elem : num)
		if (ans.empty() || ans.back() != elem)
			ans.push_back(elem);
	for (int elem : ans) cout << elem << ' ';
}