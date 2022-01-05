/*
 * 제로
 * https://www.acmicpc.net/problem/10773
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int k;	cin >> k;
	vector<int> num(k);
	for (int &elem : num) cin >> elem;
	stack<int> st;
	for (int elem : num) {
		if (elem == 0) st.pop();
		else st.push(elem);
	}
	int ans = 0;
	while (!st.empty()) {
		ans += st.top(); st.pop();
	}
	cout << ans;
}