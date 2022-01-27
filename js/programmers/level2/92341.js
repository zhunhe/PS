/*
 * 주차 요금 계산
 * https://programmers.co.kr/learn/courses/30/lessons/92341
 */

function solution(fees, records) {
	const answer = [];
	let inoutTime = new Map();
	for (const r of records) {
		let [time, car, type] = r.split(' ');
		let [h, m] = time.split(':');
		time = +h * 60 + +m;
		if (type === "IN")
			inoutTime.set(car, (inoutTime.get(car) || 0) + 1439 - time);
		else
			inoutTime.set(car, (inoutTime.get(car) || 0) - 1439 + time);
	}
	inoutTime = new Map([...inoutTime.entries()].sort());
	for (const [car, time] of inoutTime) {
		let fee = fees[1];
		if (time > fees[0])
			fee += Math.ceil((time - fees[0]) / fees[2]) * fees[3];
		answer.push(fee);
	}
	return answer;
}