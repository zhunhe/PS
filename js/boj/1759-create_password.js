/*
[boj] 암호 만들기(1759번)
https://www.acmicpc.net/problem/1759
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
    process.platform === "linux" ? "/dev/stdin" : "./testcase/1759.txt";
let input = fs
    .readFileSync(filePath)
    .toString()
    .trim()
    .split("\n");
const len = parseInt(input[0].split(" ")[0]);
const num = parseInt(input[0].split(" ")[1]);

let eng = [];
eng = input[1].split(" ");
eng.sort();

let answer = [];
let tmp = [];

function countVowels(string) {
    let count = 0;
    const checker = ["a", "e", "i", "o", "u"];

    for (let char of string) {
        if (checker.includes(char)) count++;
    }
    return count;
}
function countConsonant(string) {
    let count = 0;
    const checker = [
        "b",
        "c",
        "d",
        "f",
        "g",
        "h",
        "j",
        "k",
        "l",
        "m",
        "n",
        "p",
        "q",
        "r",
        "s",
        "t",
        "v",
        "w",
        "x",
        "y",
        "z"
    ];

    for (let char of string) {
        if (checker.includes(char)) count++;
    }
    return count;
}

function DFS(L, s) {
    if (L === len) {
        if (countVowels(tmp) >= 1 && countConsonant(tmp) >= 2)
            answer.push(tmp.slice());
        return;
    }
    for (let i = s; i < num; i++) {
        tmp.push(eng[i]);
        DFS(L + 1, i + 1);
        tmp.pop();
    }
}

DFS(0, 0);
for (let i = 0; i < answer.length; i++) {
    console.log(answer[i].join(""));
}
