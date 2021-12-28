/*
 * 가장높은탑쌓기
 * https://www.acmicpc.net/problem/2655
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define AREA	0
#define HEIGHT	1
#define WEIGHT	2
#define INDEX	3

bool compare(vector<int> front, vector<int> end) {
	if (front[0] == end[0]) return (front[1] > end[1]);
	else return (front[0] > end[0]);
}

int main() {
	int n;	cin >> n;
	vector<vector<int> > brick(n, vector<int>(4));
	for (int i = 0; i < n; i++) {
		cin >> brick[i][AREA] >> brick[i][HEIGHT] >> brick[i][WEIGHT];
		brick[i][INDEX] = i + 1;
	}
	sort(brick.begin(), brick.end(), compare);
	vector<vector<int> > idx(n, vector<int>(1));
	for (int i = 0; i < n; i++) idx[i][0] = brick[i][INDEX];
	vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		dp[i] = brick[i][HEIGHT];
		for (int j = 0; j < i; j++) {
			if (brick[i][WEIGHT] > brick[j][WEIGHT]) continue;
			if (dp[i] >= dp[j] + brick[i][HEIGHT]) continue;
			dp[i] = dp[j] + brick[i][HEIGHT];
			idx[i].resize(0);
			idx[i].push_back(brick[i][INDEX]);
			for (int elem : idx[j])
				if (elem) idx[i].push_back(elem);
		}
	}
	int answer;
	int height = 0;
	for (int i = 0; i < n; i++) {
		if (height >= dp[i]) continue;
		answer = i;
		height = dp[i];
	}
	cout << idx[answer].size() << '\n';
	for (int elem : idx[answer])
		cout << elem << '\n';
};