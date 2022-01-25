/*
 * 크레인 인형뽑기 게임
 * https://programmers.co.kr/learn/courses/30/lessons/64061
 */

#include "bits/stdc++.h"
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> st;
	for (int x : moves) {
		x--;
		for (int y = 0; y < board.size(); y++) {
			if (board[y][x] == 0) continue;
			if (st.empty() || st.top() != board[y][x]) {
				st.push(board[y][x]);
			} else {
				st.pop();
				answer += 2;
			}
			board[y][x] = 0;
			break;
		}
	}
	return answer;
}

int main() {
	vector<vector<vector<int>>> board{
		{{0,0,0,0,0},
		 {0,0,1,0,3},
		 {0,2,5,0,1},
		 {4,2,4,4,2},
		 {3,5,1,3,1}}
	};
	vector<vector<int>> moves{
		{1,5,3,5,1,2,1,4}
	};
	vector<int> want{
		4
	};
	for (int i = 0; i < want.size(); i++) {
		int got = solution(board[i], moves[i]);
		cout << (want[i] == got ? "OK!" : "FAIL! ") << " want:[" << want[i] << "] got:[" << got << "]\n";
	}
}