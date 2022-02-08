/*
 * 시리얼 번호
 * https://www.acmicpc.net/problem/1431
 */

#include "bits/stdc++.h"
using namespace std;

int get_sum(string s) {
	int sum = 0;
	for (char c : s)
		if ('0' <= c && c <= '9')
			sum += c - '0';
	return sum;
}

int main() {
	int n;	cin >> n;
	vector<string> v(n);
	for (string &elem : v) cin >> elem;
	sort(v.begin(), v.end(), [&](string front, string back){
		if (front.size() == back.size()) {
			int f_sum = get_sum(front), b_sum = get_sum(back);
			if (f_sum == b_sum)
				return front < back;
			return f_sum < b_sum;
		}
		return front.size() < back.size();
	});
	for (string elem : v)
		cout << elem << '\n';
}
