/*
[boj] OX퀴즈(8958번)
https://www.acmicpc.net/problem/8958
*/

function solution(OX_result) {
  let answer = 0;
  let score = 0;

  for (let i = 0; i < OX_result.length; i++) {
    if (OX_result[i] === "O") {
      score++;
    } else {
      score = 0;
    }
    answer += score;
  }
  return answer;
}

input = [
  "OOXXOXXOOO",
  "OOXXOOXXOO",
  "OXOXOXOXOXOXOX",
  "OOOOOOOOOO",
  "OOOOXOOOOXOOOOX"
];
output = [10, 9, 7, 55, 30];

for (let i = 0; i < input.length; i++) {
  console.log(output[i], solution(input[i]));
}
