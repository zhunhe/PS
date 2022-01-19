function solution(word) {
    const word_set = ["", "A", "E", "I", "O", "U"];
    let all_word = [];
    function dfs(depth, tmp) {
        if (depth === 5) {
            all_word.push(tmp);
            return;
        }
        for (let i = 0; i < word_set.length; i++)
            dfs(depth + 1, tmp + word_set[i]);
    }
    dfs(0, "");
    all_word = [...new Set(all_word)].sort();
    return all_word.indexOf(word, 0);
}

word = ["AAAAE", "AAAE", "I", "EIO"];
result = [6, 10, 1563, 1189];
for (let i = 0; i < word.length; i++) {
    console.log(result[i], solution(word[i]));
}