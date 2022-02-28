/*
 * 수 묶기
 * https://www.acmicpc.net/problem/1744
 */

#include "bits/stdc++.h"
using namespace std;
int ans;

int main() {
	int n;	cin >> n;
	vector<int> posi, nega;
	while (n--) {
		int tmp;	cin >> tmp;
		if (tmp > 0) posi.push_back(tmp);
		else nega.push_back(tmp);
	}
	sort(posi.begin(), posi.end(), [&](int front, int end) {
		return front > end;
	});
	sort(nega.begin(), nega.end());
	for (int i = 0; i < posi.size(); i++) {
		if (i < posi.size() - 1 && posi[i] * posi[i + 1] > posi[i] + posi[i + 1]) {
			ans += posi[i] * posi[i + 1];
			i++;
		} else
			ans += posi[i];
	}
	for (int i = 0; i < nega.size(); i++) {
		if (i < nega.size() - 1 && nega[i] * nega[i + 1] > nega[i] + nega[i + 1]) {
			ans += nega[i] * nega[i + 1];
			i++;
		} else
			ans += nega[i];
	}
	cout << ans;
}