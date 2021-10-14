/*
[프로그래머스] 타겟 넘버
https://programmers.co.kr/learn/courses/30/lessons/43165
*/

function solution(nums, target) {
    let answer = 0;
    let n = nums.length;

    function DFS(L, sum) {
        if (L === n) {
            if (sum === target) {
                answer++;
            }
            return;
        } else {
            DFS(L + 1, sum - nums[L]);
            DFS(L + 1, sum + nums[L]);
        }
    }
    DFS(0, 0);
    return answer;
}

nums = [1, 1, 1, 1, 1];
target = 3;
output = 5;

console.log(output, solution(nums, target));