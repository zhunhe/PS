#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
vector<pair<int, int> > v;
priority_queue<int, vector<int>, greater<int> > q;

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}
}

int solve_GREEDY() {
	sort(v.begin(), v.end());
	q.push(v[0].second);
	int m = 1;
	for (int i = 1; i < n; i++)	{
		while (!q.empty() && q.top() <= v[i].first)
			q.pop();
		q.push(v[i].second);
		m = max(m, (int)q.size());
	}
	return m;
}

int main() {
	set_input_data();
	cout << solve_GREEDY();
}