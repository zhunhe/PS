/*
 * 잃어버린 괄호
 * https://www.acmicpc.net/problem/1541
 */

#include "bits/stdc++.h"
using namespace std;
int ans;

string addSpace(string s) {
	string ret = "";
	for (char c : s) {
		if (c == '-' || c == '+')
			ret += " ";
		ret += c;
		if (c == '-' || c == '+')
			ret += " ";
	}
	return ret;
}

vector<string> stringToVector(string s) {
	vector<string> ret;
	string tmp = "";
	for (char c : s) {
		if (c == ' ') {
			ret.push_back(tmp);
			tmp = "";
		} else {
			tmp += c;
		}
	}
	ret.push_back(tmp);
	return ret;
}

int main() {
	string s;	cin >> s;
	vector<string> v = stringToVector(addSpace(s));
	bool minus = false;
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "-") minus = true;
		if (v[i] != "-" && v[i] != "+")
			ans += (minus ? -stoi(v[i]) : stoi(v[i]));
	}
	cout << ans;
}