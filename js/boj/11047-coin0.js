/*
[boj] 동전 0(11047)
https://www.acmicpc.net/problem/11047
*/

const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/11047.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = parseInt(input[0].split(" ")[0]);
let money = parseInt(input[0].split(" ")[1]);
let coin = [];
for (let i = 1; i < n + 1; i++) {
    coin.push(parseInt(input[i]));
}

answer = 0;
for (let i = coin.length - 1; i >= 0; i--) {
    while (money - coin[i] >= 0) {
        money -= coin[i];
        answer++;
    }
}
console.log(answer);