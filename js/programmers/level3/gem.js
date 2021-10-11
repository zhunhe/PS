/*
보석 쇼핑

[input]
gems: 보석들의 리스트
[return]
answer: 보석들을 최소 1개 이상 포함하는 가장 짧은 구간
*/

function solution(gems) {
    let gemset = new Set(gems);
    let sH = new Map();
    let answer = [0, gems.length - 1];

    for (let i = 0; i < gemset.size - 1; i++) {
        sH.set(gems[i], (sH.get(gems[i]) || 0) + 1);
    }
    let st = 0;
    for (let en = gemset.size - 1; en < gems.length; en++) {
        sH.set(gems[en], (sH.get(gems[en]) || 0) + 1);
        while (sH.size === gemset.size) {
            if (en - st < answer[1] - answer[0]) {
                answer = [st, en];
            }
            sH.set(gems[st], (sH.get(gems[st]) || 0) - 1);
            if (sH.get(gems[st]) === 0) {
                sH.delete(gems[st]);
            }
            st++;
        }
    }
    return [answer[0] + 1, answer[1] + 1];
}

input = ["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"];
output = [3, 7];
console.log("input:", input, "got:", solution(input), "want:", output);