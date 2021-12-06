/*
 * 멀티탭 스케줄링
 * https://www.acmicpc.net/problem/1700
 */

#include <iostream>
#include <vector>
using namespace std;

#define MAX		100

int n, k;
vector<int> order;
bool is_plugged[MAX];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int elec;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> elec;
		order.push_back(elec);
	}
}

int solve_GREEDY() {
	vector<int> running;
	int answer = 0;

	for (int i = 0; i < order.size(); i++) {
		int curr = order[i];

		if (is_plugged[curr]) continue;
		if (running.size() < n) {
			running.push_back(curr);
			is_plugged[curr] = true;
			continue;
		}
		int t = 0;
		int victim;
		for (int j = 0; j < running.size(); j++) {
			int tmp = MAX;
			for (int k = i + 1; k < order.size(); k++) {
				if (order[k] == running[j]) {
					tmp = k;
					break;
				}
			}
			if (tmp > t) {
				t = tmp;
				victim = j;
			}
		}
		int target = running[victim];
		is_plugged[target] = false;
		running[victim] = curr;
		is_plugged[curr] = true;
		answer++;
	}
	return answer;
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
	return 0;
}