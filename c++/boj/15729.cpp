/*
 * 방탈출
 * https://www.acmicpc.net/problem/15729
 */

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int light[1000000];

void set_input_data() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> light[i];
	}
}

// ❗️모든 불이 꺼져있는 상태에서 입력받은 형태로 불을 켜기위해 누르는 버튼의 최소값을 구하는 문제
// 버튼을 누를시 뒤에 2개 버튼도 같이 눌림
// 모두 꺼진 상태에서 켜기 위한 횟수와 켜진 상태에서 모두 끄기 위해 누르는 버튼 횟수는 같음
int GREEDY() {
	int answer = 0;

	// 앞에서부터 켜진 것만 찾아서 꺼주면서 횟수를 기록하면 문제풀이 끝
	for (int i = 0; i < n; i++) {
		if (light[i] == 0) continue;
		answer++;
		for (int j = 0; j < 3 && j < n; j++) {
			// 켜진건 끄고 꺼진건 켜고
			light[i + j] ^= 1;
		}
	}
	return answer;
}

int main() {
	set_input_data();
	cout << GREEDY();
}