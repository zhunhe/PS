/*
[leetcode] 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/
*/

var islandPerimeter = function (grid) {
    let line = 0;

    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            if (grid[i][j] === 0) {
                continue;
            }
            if (j === 0 || grid[i][j - 1] === 0) {
                line++;
            }
            if (j === grid[i].length - 1 || grid[i][j + 1] === 0) {
                line++;
            }
            if (i === 0 || grid[i - 1][j] === 0) {
                line++;
            }
            if (i === grid.length - 1 || grid[i + 1][j] === 0) {
                line++;
            }
        }
    }
    return line;
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
    console.log(output[i], islandPerimeter(testcases[i]));
}
