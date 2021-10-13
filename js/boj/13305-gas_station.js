/*
[boj] 주유소(13305번)
https://www.acmicpc.net/problem/13305
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/13305.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

// 도시 갯수
const n = parseInt(input[0]);

// 도시간 거리
let len = [];
for (let i = 0; i < n - 1; i++) {
    len.push(parseInt(input[1].split(" ")[i]));
}
// 기름 가격
let price = [];
for (let i = 0; i < n; i++) {
    price.push(parseInt(input[2].split(" ")[i]));
}
// 가격 계산
let min_price = price[0];
let answer = 0;
for (let i = 0; i < len.length; i++) {
    min_price = Math.min(min_price, price[i]);
    answer += parseInt(min_price) * parseInt(len[i]);
}
console.log(answer);