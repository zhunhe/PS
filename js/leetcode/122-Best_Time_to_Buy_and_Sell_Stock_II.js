/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
    let answer = 0;
    let profit = 0;

    for (let i = 1; i < prices.length; i++) {
        if (prices[i - 1] < prices[i]) {
            profit += (prices[i] - prices[i - 1]);
        } else {
            answer += profit;
            profit = 0;
        }
    }
    return answer + profit;
}

input = [7, 1, 5, 3, 6, 4];
output = 7;
console.log(output, maxProfit(input))