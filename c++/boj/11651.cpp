/*
 * 좌표 정렬하기 2
 * https://www.acmicpc.net/problem/11651
 */

#include "bits/stdc++.h"
using namespace std;
struct coor {
	int y, x;
};

int main() {
	int n;  cin >> n;
	vector<coor> point(n);
	for (coor &elem : point) cin >> elem.y >> elem.x;
	sort(point.begin(), point.end(), [&](coor front, coor back){
		if (front.x == back.x)
			return front.y < back.y;
		return front.x < back.x;
	});
	for (coor elem : point) cout << elem.y << ' ' << elem.x << '\n';
}