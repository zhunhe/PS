/*
[boj] 잃어버린 괄호(1541번)
https://www.acmicpc.net/problem/1541
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/1541.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");
let l_input = [...input[0]];

let tmp = "";
let list = [];
for (let i = 0; i < l_input.length; i++) {
    if (!isNaN(l_input[i])) {
        tmp = tmp + l_input[i];
    } else {
        if (tmp !== "") {
            list.push(tmp);
            tmp = "";
        }
        if (l_input[i] === '+' || l_input[i] === '-') {
            list.push(l_input[i]);
        }
    }
}
if (tmp !== "") {
    list.push(tmp);
}

let flag = true;
let answer = 0;
for (let i = 0; i < list.length; i++) {
    if (list[i] === '-') {
        flag = false;
    }
    if (!isNaN(list[i])) {
        if (flag) {
            answer += parseInt(list[i]);
        } else {
            answer -= parseInt(list[i]);
        }
    }
}
console.log(answer);