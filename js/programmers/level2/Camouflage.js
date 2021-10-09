/*
[프로그래머스] 위장
https://programmers.co.kr/learn/courses/30/lessons/42578
*/

function solution(clothes) {
    let answer = 1;
    let sH = new Map();
    for (let [val, key] of clothes) {
        sH.set(key, (sH.get(key) || 0) + 1);
    }
    for (let [key, val] of sH) {
        answer *= (val + 1);
    }
    return answer - 1;
}

input = [
    [["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]],
    [["crowmask", "face"], ["bluesunglasses", "face"], ["smoky_makeup", "face"]]
]
output = [
    5, 3
]

for (let i = 0; i < input.length; i++) {
    console.log(output[i], solution(input[i]));
}