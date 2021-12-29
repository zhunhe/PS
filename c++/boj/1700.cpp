/*
 * 멀티탭 스케줄링
 * https://www.acmicpc.net/problem/1700
 */

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int n, k;
int order[MAX + 1];
vector<int> tab;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 0; i < k; i++)
		cin >> order[i];
}

bool is_plugged(int device) {
	if (tab.empty())
		return false;
	for (int t = 0; t < tab.size(); t++)
		if (tab[t] == device)
			return true;
	return false;
}

bool is_exist_empty_plug() {
	if (tab.size() < n)
		return true;
	return false;
}

void switch_device(int curr_idx, int device) {
	int farthest = 0;
	int tab_idx = 0;

	for (int t = 0; t < tab.size(); t++) {
		int tmp = MAX;
		for (int j = curr_idx + 1; j < k; j++) {
			if (tab[t] == order[j]) {
				tmp = j;
				break;
			}
		}
		if (farthest < tmp) {
			farthest = tmp;
			tab_idx = t;
		}
	}
	tab[tab_idx] = device;
}

int GREEDY() {
	int ans = 0;

	for (int i = 0; i < k; i++) {
		if (is_plugged(order[i]))
			continue;
		if (is_exist_empty_plug()) {
			tab.push_back(order[i]);
			continue;
		}
		switch_device(i, order[i]);
		ans++;
	}
	return ans;
}

int main() {
	set_input_data();
	cout << GREEDY();
}