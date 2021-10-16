/*
[boj] 문자열 폭발(9935)
https://www.acmicpc.net/problem/9935
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath =
    process.platform === "linux" ? "/dev/stdin" : "./testcase/9935.txt";
let input = fs
    .readFileSync(filePath)
    .toString()
    .trim()
    .split("\n");
let string = input[0];
const charset = input[1];

let tmp = [];
for (let char of string) {
    tmp.push(char);

    let flag = true;
    if (tmp.length >= charset.length) {
        let k = 0;
        for (let j = charset.length - 1; j >= 0; j--, k++) {
            if (charset[j] !== tmp[tmp.length - 1 - k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            while (k) {
                tmp.pop();
                k--;
            }
        }
    }
}
if (tmp.length) console.log(tmp.join(""));
else console.log("FRULA");
