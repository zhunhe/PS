var floodFill = function (image, sr, sc, newColor) {
    let xlen = image[0].length;
    let ylen = image.length;
    let orgColor = image[sr][sc];

    function DFS(i, j) {
        image[i][j] = newColor;
        if (orgColor === newColor) return;
        if (i > 0 && image[i - 1][j] === orgColor) DFS(i - 1, j);
        if (i < ylen - 1 && image[i + 1][j] === orgColor) DFS(i + 1, j);
        if (j > 0 && image[i][j - 1] === orgColor) DFS(i, j - 1);
        if (j < xlen - 1 && image[i][j + 1] === orgColor) DFS(i, j + 1);
    }
    DFS(sr, sc);
    return image;
};

image = [
    [
        [1, 1, 1],
        [1, 1, 0],
        [1, 0, 1],
    ],
    [
        [0, 0, 0],
        [0, 0, 0],
    ],
    [
        [0, 0, 0],
        [0, 1, 1],
    ],
];

sr = [1, 0, 1];
sc = [1, 0, 1];
newColor = [2, 2, 1];
output = [
    [
        [2, 2, 2],
        [2, 2, 0],
        [2, 0, 1],
    ],
    [
        [2, 2, 2],
        [2, 2, 2],
    ],
    [
        [0, 0, 0],
        [0, 1, 1],
    ],
];

for (let i = 0; i < output.length; i++) {
    console.log(output[i], floodFill(image[i], sr[i], sc[i], newColor[i]));
}
