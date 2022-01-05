/*
 * 최소 힙
 * https://www.acmicpc.net/problem/1927
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> arr(n);
	for (int &elem : arr) cin >> elem;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int elem : arr) {
		if (elem == 0) {
			if (pq.empty())
				cout << 0 << '\n';
			else {
				cout << pq.top() << '\n'; pq.pop();
			}
		} else {
			pq.push(elem);
		}
	}
}