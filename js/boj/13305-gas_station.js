/*
[boj] 주유소(13305번)
https://www.acmicpc.net/problem/13305
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === "linux" ? "/dev/stdin" : "./testcase/13305.txt";
let input = fs.readFileSync(filePath).toString().trim().split("\n");

const n = parseInt(input[0]);
const DIST = 1;
const PRICE = 2;

let answer = 0;
let oilPrice = BigInt(input[PRICE].split(" ")[0]);
console.log(oilPrice);
for (let i = 0; i < n - 1; i++) {
	if (BigInt(input[PRICE].split(" ")[i]) < oilPrice) oilPrice = BigInt(input[PRICE].split(" ")[i]);
	let distance = BigInt(input[DIST].split(" ")[i]);
	answer += distance * oilPrice;
}
console.log(answer);
