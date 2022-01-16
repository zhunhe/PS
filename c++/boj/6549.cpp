/*
 * 히스토그램에서 가장 큰 직사각형
 * https://www.acmicpc.net/problem/6549
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	while (1) {
		int n;	cin >> n;
		long long ans = 0;
		if (n == 0)
			return 0;
		vector<long long> arr(n + 2);
		for (int i = 1; i <= n; i++) cin >> arr[i];
		stack<long long> st;	st.push(0);
		for (int i = 1; i <= n + 1; i++) {
			while (st.size() && arr[st.top()] > arr[i]) {
				long long height = arr[st.top()]; st.pop();
				long long width = i - st.top() - 1;
				ans = max(ans, height * width);
			}
			st.push(i);
		}
		cout << ans << '\n';
	}
}