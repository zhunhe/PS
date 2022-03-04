/*
 * 마스크가 필요해
 * https://www.acmicpc.net/problem/19580
 */

#include "bits/stdc++.h"
using namespace std;
struct citizenData {
	long long low, high;
	bool operator<(const citizenData &Ob) const {
		return high > Ob.high;
	}
};
struct shopData {
	long long price, count;
};
int ans;

int main() {
	int n, m;	cin >> n >> m;
	vector<citizenData> citizen(n);
	for (citizenData &elem : citizen) cin >> elem.low >> elem.high;
	vector<shopData> shop(m);
	for (shopData &elem : shop) cin >> elem.price >> elem.count;
	sort(citizen.begin(), citizen.end(), [&](citizenData front, citizenData back) {
		if (front.low == back.low)
			return front.high < back.high;
		return front.low < back.low;
	});
	sort(shop.begin(), shop.end(), [&](shopData front, shopData back) {
		return front.price < back.price;
	});
	priority_queue<citizenData> pq;
	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j < n && citizen[j].low <= shop[i].price) {
			if (citizen[j].high >= shop[i].price)
				pq.push(citizen[j]);
			j++;
		}
		while (!pq.empty() && shop[i].count) {
			citizenData tmp = pq.top();	pq.pop();
			if (tmp.low <= shop[i].price && shop[i].price <= tmp.high) {
				shop[i].count--;
				ans++;
			}
		}
	}
	cout << ans;
}