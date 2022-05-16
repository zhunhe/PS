/*
 * 주사위 쌓기
 * https://www.acmicpc.net/problem/15703
 */

#include "bits/stdc++.h"
using namespace std;

int main() {
	int n;	cin >> n;
	vector<int> dice(n), tower;
	for (int &elem : dice) cin >> elem;
	sort(dice.begin(), dice.end());
	for (int elem : dice) {
		bool input = false;
		for (int i = 0; i < tower.size(); i++) {
			if (tower[i] <= elem) {
				tower[i]++;
				input = true;
				break;
			}
		}
		if (!input)
			tower.push_back(1);
	}
	cout << tower.size();
}
