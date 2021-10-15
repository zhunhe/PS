var numIslands = function (grid) {
    let answer = 0;
    const ylen = grid.length;
    const xlen = grid[0].length;

    for (let i = 0; i < ylen; i++) {
        for (let j = 0; j < xlen; j++) {
            if (grid[i][j] === "1") {
                answer++;
                DFS(i, j);
            }
        }
    }
    function DFS(i, j) {
        grid[i][j] = "2";

        if (i > 0 && grid[i - 1][j] === "1") DFS(i - 1, j);
        if (j > 0 && grid[i][j - 1] === "1") DFS(i, j - 1);
        if (i < ylen - 1 && grid[i + 1][j] === "1") DFS(i + 1, j);
        if (j < xlen - 1 && grid[i][j + 1] === "1") DFS(i, j + 1);
    }
    return answer;
};

grid = [
    [
        ["1", "1", "1", "1", "0"],
        ["1", "1", "0", "1", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "0", "0", "0"],
    ],
    [
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ],
];
output = [1, 3];
for (let i = 0; i < output.length; i++)
    console.log(output[i], numIslands(grid[i]));
