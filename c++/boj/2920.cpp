/*
 * 음계
 * https://www.acmicpc.net/problem/2920
 */

#include "bits/stdc++.h"
using namespace std;

#define INIT	""
#define ASCEND	"ascending"
#define DESCEND	"descending"
#define MIXED	"mixed"

int main() {
	string type = INIT;
	stack<int> st;
	for (int i = 0; i < 8; i++) {
		int tmp;	cin >> tmp;
		if (st.size()) {
			if (type == INIT) {
				if (tmp > st.top())
					type = ASCEND;
				else
					type = DESCEND;
			} else {
				if (tmp > st.top() && type == DESCEND)
					type = MIXED;
				else if (tmp < st.top() && type == ASCEND)
					type = MIXED;
			}
		}
		st.push(tmp);
	}
	cout << type;
}