/*
[프로그래머스] 기능개발
https://programmers.co.kr/learn/courses/30/lessons/42586?language=javascript
*/

function solution(progresses, speeds) {
    let answer = [];
    let remain = [];

    for (let i = 0; i < progresses.length;i++) {
        remain.push(Math.ceil((100 - progresses[i]) / speeds[i]));
    }
    answer.push(1);
    let left = 0;
    for (let right = 1; right < remain.length; right++) {
        if (remain[right] <= remain[left]) {
            answer[answer.length - 1]++;
        } else {
            answer.push(1);
            left = right;
        }
    }
    return answer;
}

progresses = [
    [93, 30, 55],
    [95, 90, 99, 99, 80, 99]
];
speeds = [
    [1, 30, 5],
    [1, 1, 1, 1, 1, 1]
]
output = [
    [2, 1],
    [1, 3, 2]
]

for (let i = 0; i < output.length; i++) {
    console.log(output[i], solution(progresses[i], speeds[i]));
}