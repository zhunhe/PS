/*
 * 이차원 배열과 연산
 * https://www.acmicpc.net/problem/17140
 */

#include "bits/stdc++.h"
using namespace std;

int t;
int height = 3, width = 3;
int A[101][101];

void calculateR() {
	for (int i = 1; i <= 100; i++) {
		map<int, int> hash;
		for (int j = 1; j <= 100; j++) {
			if (A[i][j])
				hash[A[i][j]]++;
			A[i][j] = 0;
		}
		priority_queue<pair<int, int>> pq;
		for (auto elem : hash)
			pq.push({-elem.second, -elem.first});
		width = max(width, (int)pq.size() * 2);
		if (width >= 100) width = 100;
		int j = 1;
		while (!pq.empty()) {
			if (j == 101) break;
			A[i][j++] = -pq.top().second;
			A[i][j++] = -pq.top().first;
			pq.pop();
		}
	}
}

void calculateC() {
	for (int j = 1; j <= 100; j++) {
		map<int, int> hash;
		for (int i = 1; i <= 100; i++) {
			if (A[i][j])
				hash[A[i][j]]++;
			A[i][j] = 0;
		}
		priority_queue<pair<int, int>> pq;
		for (auto elem : hash)
			pq.push({-elem.second, -elem.first});
		height = max(height, (int)pq.size() * 2);
		if (height >= 100) height = 100;
		int i = 1;
		while (!pq.empty()) {
			if (i == 101) break;
			A[i++][j] = -pq.top().second;
			A[i++][j] = -pq.top().first;
			pq.pop();
		}
	}
}

int main() {
	int r, c, k;	cin >> r >> c >> k;
	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			cin >> A[i][j];
	for (t = 0; t <= 100; t++) {
		if (A[r][c] == k) break;
		if (height >= width)
			calculateR();
		else
			calculateC();
	}
	cout << (t > 100 ? -1 : t);
}