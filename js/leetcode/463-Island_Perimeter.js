/*
[leetcode] 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/
*/

// iterative
var islandPerimeter = function (grid) {
    let answer = 0;

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 0) {
                continue;
            }
            if (j === 0 || grid[i][j - 1] === 0) {
                answer++;
            }
            if (j === grid[i].length - 1 || grid[i][j + 1] === 0) {
                answer++;
            }
            if (i === 0 || grid[i - 1][j] === 0) {
                answer++;
            }
            if (i === grid.length - 1 || grid[i + 1][j] === 0) {
                answer++;
            }
        }
    }
    return answer;
};

// dfs
var islandPerimeterDFS = function (grid) {
    let answer = 0;
    let len = grid.length;

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 1) {
                DFS(i, j);
            }
        }
    }
    function DFS(i, j) {
        grid[i][j] = 2; // visited

        if (j === 0 || grid[i][j - 1] === 0) answer++;
        if (j === len - 1 || grid[i][j + 1] === 0) answer++;
        if (i === 0 || grid[i - 1][j] === 0) answer++;
        if (i === len - 1 || grid[i + 1][j] === 0) answer++;

        if (i > 0 && grid[i - 1][j] === 1) DFS(i - 1, j);
        if (j > 0 && grid[i][j - 1] === 1) DFS(i, j - 1);
        if (i < len - 1 && grid[i + 1][j] === 1) DFS(i + 1, j);
        if (j < len - 1 && grid[i][j + 1] === 1) DFS(i, j + 1);
    }
    return answer;
};

testcases = [
    [
        [0, 1, 0, 0],
        [1, 1, 1, 0],
        [0, 1, 0, 0],
        [1, 1, 0, 0],
    ],
    [[1]],
    [[1, 0]],
];
output = [16, 4, 4];

for (let i = 0; i < output.length; i++) {
    console.log(output[i], islandPerimeterDFS(testcases[i]));
}
