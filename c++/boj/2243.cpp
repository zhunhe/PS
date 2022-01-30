/*
 * 사탕상자
 * https://www.acmicpc.net/problem/2243
 */

#include "bits/stdc++.h"
using namespace std;

#define MAX		1000000
int tree[MAX * 4];

void update(int index, int target, int diff, int left, int right) {
	if (target < left || target > right)
		return;
	tree[index] += diff;
	if (left == right)
		return;
	int mid = (left + right) / 2;
	update(index * 2, target, diff, left, mid);
	update(index * 2 + 1, target, diff, mid + 1, right);
}

int get_flavor(int index, int target, int left, int right) {
	if (left == right)
		return left;
	int mid = (left + right) / 2;
	if (target <= tree[index * 2])
		return get_flavor(index * 2, target, left, mid);
	else
		return get_flavor(index * 2 + 1, target - tree[index * 2], mid + 1, right);
}

int main() {
	int n;	cin >> n;
	vector<int> ans;
	while (n--) {
		int a, b, c;	cin >> a;
		if (a == 1) {
			cin >> b;
			int flavor = get_flavor(1, b, 1, MAX);
			update(1, flavor, -1, 1, MAX);
			ans.push_back(flavor);
		} else {
			cin >> b >> c;
			update(1, b, c, 1, MAX);
		}
	}
	for (int elem : ans) cout << elem << '\n';
}