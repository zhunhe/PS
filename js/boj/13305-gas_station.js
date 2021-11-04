/*
[boj] 주유소(13305번)
https://www.acmicpc.net/problem/13305
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/13305.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = +input[0];
const distance = input[1].split(" ").map((v) => BigInt(v));
const price = input[2].split(" ").map((v) => BigInt(v));

let curPrice = price[0];
let cost = 0n;

for (let i = 0; i < n - 1; i++) {
	if (curPrice > price[i]) curPrice = price[i];
	cost += curPrice * distance[i];
}
console.log(String(cost));
