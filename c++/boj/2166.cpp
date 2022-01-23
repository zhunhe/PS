/*
 * 다각형의 면적
 * https://www.acmicpc.net/problem/2166
 */

#include "bits/stdc++.h"
using namespace std;
typedef long long	ll;

struct coor{
	ll y, x;
};

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	return (x1*y2 + x2*y3 + x3*y1) - (y1*x2 + y2*x3 + y3*x1);
}

int main() {
	int n;	cin >> n;
	vector<coor> num(n);
	for (auto &elem : num) cin >> elem.x >> elem.y;
	ll x = num[0].x, y = num[0].y, ans = 0;
	for (int i = 1; i < n - 1; i++)
		ans += ccw(x, y, num[i].x, num[i].y, num[i + 1].x, num[i + 1].y);
	printf("%.1lf\n", abs(ans) / 2.0);
}