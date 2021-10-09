/*
[leetcode] Minimum Size Subarray Sum(209번)
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

function solution(nums, target) {
  let answer = Number.MAX_SAFE_INTEGER;
  let left = 0;
  let sum = 0;

  for (let right = 0; right < nums.length; right++) {
    sum += nums[right];
    while (sum > target) {
      sum -= nums[left++];
    }
    if (sum === target) {
      answer = Math.min(answer, right - left + 1);
    }
  }
  if (answer === Number.MAX_SAFE_INTEGER) return 0;
  return answer;
}

input1 = [
  [2, 3, 1, 2, 4, 3],
  [1, 4, 4],
  [1, 1, 1, 1, 1, 1, 1, 1]
];
input2 = [7, 4, 11];
output = [2, 1, 0];

for (let i = 0; i < input1.length; i++) {
  console.log(output[i], solution(input1[i], input2[i]));
}
