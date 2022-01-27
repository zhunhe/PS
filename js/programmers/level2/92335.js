/*
 * k진수에서 소수 개수 구하기
 * https://programmers.co.kr/learn/courses/30/lessons/92335
 */

function isPrime(n) {
	if (n < 2) return false;
	for (let i = 2; i * i <= n; i++)
		if (n % i === 0)
			return false;
	return true;
}

function solution(n, k) {
	let answer = 0;
	let s = n.toString(k).split('0').map(Number);
	for (const num of s)
		if (isPrime(num))
			answer++;
	return answer;
}
