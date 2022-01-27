/*
 * 신고 결과 받기
 * https://programmers.co.kr/learn/courses/30/lessons/92334
 */

function solution(id_list, report, k) {
	report = [...new Set(report)].map(a=>{return a.split(' ')});
	const answer = [...Array(id_list.length)].fill(0);
	const reported = new Map();
	for (const [reporter, bad] of report)
		reported.set(bad, (reported.get(bad) || 0) + 1);
	for (const [reporter, bad] of report)
		if (reported.get(bad) >= k)
			answer[id_list.indexOf(reporter)]++;
	return answer;
}