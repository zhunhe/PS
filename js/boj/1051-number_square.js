/*
[boj] 숫자 정사각형(1051번)
https://www.acmicpc.net/problem/1051
*/

// 파일로부터 값 입력 받기
const fs = require("fs");
const filePath = process.platform === 'linux' ? '/dev/stdin' : './testcase/1051.txt';
let input = fs.readFileSync(filePath).toString().trim().split("\n");
const n = parseInt(input[0].split(" ")[0]);
const m = parseInt(input[0].split(" ")[1]);
for (let i = 1; i < n + 1; i++) {
    input[i] = input[i].split("").map(item => +item);
}


// 테두리는 -1로 둘러침
let board = [...Array(n + 2)].map(e => Array(m + 2).fill(-1));

// ./testcase/1051.txt에서 받아온 값 ~n*m사이즈 board에 저장
// 해쉬에 board에 들어가는 숫자 개수 저장
let sH = new Map();
for (let i = 1; i < input.length; i++) {
    for (let j = 0; j < input[i].length; j++) {
        board[i][j + 1] = input[i][j];
        sH.set(input[i][j], (sH.get(input[i][j]) || 0) + 1);
    }
}

let answer = 1;
for (let i = 1; i < n; i++) {
    for (let j = 1; j < m; j++) {
        // 같은 숫자로 정사각형을 이루기 위해서는 최소 4개의 숫자가 필요
        if (sH.get(board[i][j]) < 4) {
            continue;
        }
        for (let k = 1; board[i + k][j + k] != -1; k++) {
            // 왼위 꼭지점 기준으로 오위 꼭지점과 비교
            if (board[i][j] !== board[i][j + k]) {
                continue;
            }
            // 왼위 꼭지점 기준으로 왼밑 꼭지점과 비교
            if (board[i][j] !== board[i + k][j]) {
                continue;
            }
            // 왼위 꼭지점 기준으로 오밑 꼭지점과 비교
            if (board[i][j] !== board[i + k][j + k]) {
                continue;
            }
            answer = Math.max(answer, (k + 1) ** 2);
        }
    }
}
console.log(answer);

