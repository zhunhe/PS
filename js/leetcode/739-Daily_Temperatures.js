/*
[leetcode] Daily Temperatures(739)
https://leetcode.com/problems/daily-temperatures/
*/

function solution(tem) {
    let answer = [...Array(tem.length).fill(0)];
    let stack = [];

    for (let i = 0; i < tem.length; i++) {
        while (stack.length && tem[i] > tem[stack[stack.length - 1]]) {
            answer[stack[stack.length - 1]] = i - stack[stack.length - 1];
            stack.pop();
        }
        stack.push(i);
    }
    return answer;
}


temper = [
    [73,74,75,71,69,72,76,73],
    [30,40,50,60],
    [30,60,90]
]
output = [
    [1,1,4,2,1,1,0,0],
    [1,1,1,0],
    [1,1,0]
]

for (let i = 0; i < temper.length; i++) {
    console.log(output[i], solution(temper[i]));
}