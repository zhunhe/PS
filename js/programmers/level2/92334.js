/*
 * 신고 결과 받기
 * https://programmers.co.kr/learn/courses/30/lessons/92334
 */

function solution(id_list, report, k) {
	const len = id_list.length;
	const answer = [...Array(len)].fill(0);
	const nameToIdx = new Map();
	for (let i = 0; i < len; i++)
		nameToIdx.set(id_list[i], i);
	const board = [...Array(len)].map(_ => Array(len).fill(0));
	for (const s of report) {
		const name = s.split(' ');
		board[nameToIdx.get(name[0])][nameToIdx.get(name[1])] = 1;
	}
	for (let x = 0; x < len; x++) {
		let count = 0;
		for (let y = 0; y < len; y++)
			if (board[y][x]) count++;
		if (count >= k)
			for (let y = 0; y < len; y++)
				if (board[y][x])
					answer[y]++;
	}
	return answer;
}