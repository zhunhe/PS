/*
[boj] 평범한 가방(12865)
https://www.acmicpc.net/problem/12865
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/12865.txt";
let input = fs
    .readFileSync(filePath)
    .toString()
    .trim()
    .split("\n");

// 입력받은 값 세팅
const n = parseInt(input[0].split(" ")[0]);
const k = parseInt(input[0].split(" ")[1]);
const nums = [];
for (let i = 1; i < n + 1; i++) {
    nums[i - 1] = input[i].split(" ").map(item => +item);
}
// dp table
let dp = [...Array(n + 1)].map(_ => Array(k + 1).fill(0));

const WEIGHT = 0;
const PRICE = 1;
for (let i = 1; i <= n; i++) {
    const [weight, price] = nums[i - 1];
    for (let j = 1; j <= k; j++) {
        if (j < weight) dp[i][j] = dp[i - 1][j];
        else dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - weight] + price);
    }
}
console.log(dp[n][k]);
