/*
[프로그래머스] 전화번호 목록
https://programmers.co.kr/learn/courses/30/lessons/42577
*/

function solution(nums) {
  let sH = new Map();
  let min_length = Number.MAX_SAFE_INTEGER;
  let max_length = Number.MIN_SAFE_INTEGER;

  for (let i = 0; i < nums.length; i++) {
    if (sH.has(nums[i])) {
      return false;
    }
    sH.set(nums[i], (sH.get(nums[i]) || 0) + 1);
    min_length = Math.min(min_length, nums[i].length);
    max_length = Math.max(max_length, nums[i].length);
  }
  for (let split_len = min_length; split_len < max_length; split_len++) {
    for (let i = 0; i < nums.length; i++) {
      if (nums[i].length < split_len) {
        continue;
      }
      tmp = nums[i].substring(0, split_len + 1);
      if (sH.has(tmp)) {
        return false;
      }
    }
  }
  return true;
}

input = [
  ["119", "97674223", "1195524421"],
  ["123", "456", "789"],
  ["12", "123", "1235", "567", "88"]
];
output = [false, true, false];

for (let i = 0; i < input.length; i++) {
  console.log(output[i], solution(input[i]));
}
