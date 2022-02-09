/*
 * 국영수
 * https://www.acmicpc.net/problem/10825
 */

#include "bits/stdc++.h"
using namespace std;
struct sData {
	string name;
	int korean, english, math;
};

int main() {
	int n;	cin >> n;
	vector<sData> student(n);
	for (sData &e : student)
		cin >> e.name >> e.korean >> e.english >> e.math;
	sort(student.begin(), student.end(), [&](sData front, sData back){
		if (front.korean == back.korean) {
			if (front.english == back.english) {
				if (front.math == back.math)
					return front.name < back.name;
				return front.math > back.math;
			}
			return front.english < back.english;
		}
		return front.korean > back.korean;
	});
	for (sData e : student)
		cout << e.name << '\n';
}