/*
 * 히스토그램
 * https://www.acmicpc.net/problem/1725
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n, ans = 0;	cin >> n;
	vector<int> arr(n + 2);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	stack<int> st;	st.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (st.size() && arr[st.top()] > arr[i]) {
			int height = arr[st.top()]; st.pop();
			int width = i - st.top() - 1;
			ans = max(ans, height * width);
		}
		st.push(i);
	}
	cout << ans;
}