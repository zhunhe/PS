/*
[leetcode] 39. Combination Sum
https://leetcode.com/problems/combination-sum/
*/

var combinationSum = function (candidates, target) {
	let answer = [];
	let tmp = [];

	function sumOfElements(nums) {
		let sum = 0;

		for (let n of nums) {
			sum += n;
		}
		return sum;
	}
	function DFS(tmp, s) {
		if (sumOfElements(tmp) > target) return;
		if (sumOfElements(tmp) === target) {
			tmp.sort((a, b) => a - b);
			answer.push(tmp.slice());
			return;
		}
		for (let i = s; i < candidates.length; i++) {
			tmp.push(candidates[i]);
			DFS(tmp, i);
			tmp.pop();
		}
	}
	DFS(tmp, 0);
	return answer;
};

let candidates = [2, 3, 6, 7];
let target = 7;
let Output = [[2, 2, 3], [7]];
console.log(Output, combinationSum(candidates, target));
