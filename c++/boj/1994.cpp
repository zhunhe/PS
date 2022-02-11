/*
* 등차수열
* https://www.acmicpc.net/problem/1994
*/

#include "bits/stdc++.h"
using namespace std;
#define MAXN		2001
#define INVALID		-1
#define INIT		0
int cache[MAXN][MAXN];
vector<int> arr;
int n;

int findNextIndex(int target, int left) {
	int right = n, mid = (left + right) / 2;
	while (left < right) {
		mid = (left + right) / 2;
		if (arr[mid] < target) left = mid + 1;
		else right = mid - 1;
	}
	if (left < n + 1 && arr[left] == target) return left;
	if (arr[mid] == target) return mid;
	return INVALID;
}

int dp(int left, int right) {
	if (left > right) return 0;
	if (left == right) return 1;
	int &ret = cache[left][right];
	if (ret != INIT) return ret;
	int diff = arr[right] - arr[left];
	int next = arr[right] + diff;
	int nextIndex = findNextIndex(next, right + 1);
	if (nextIndex == INVALID) return ret = 2;
	return ret = dp(right, nextIndex) + 1;
}

int main() {
	cin >> n;
	arr.resize(n);
	for (int &elem : arr) cin >> elem;
	sort(arr.begin(), arr.end());
	int ans = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = max(ans, dp(i, j));
	cout << ans;
}