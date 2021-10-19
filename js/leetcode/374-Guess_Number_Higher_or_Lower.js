var guessNumber = function (n) {
	let left = 1;
	let right = n;
	let mid = parseInt((left + right) / 2);

	while (left <= right) {
		if (guess(mid) === 0) break;
		if (guess(mid) === 1) left = mid + 1;
		else right = mid - 1;
		mid = parseInt((left + right) / 2);
	}
	return mid;
};

function guess(num) {
	if (pick < num) return -1;
	else if (pick > num) return 1;
	else return 0;
}

n = 10;
pick = 6;
output = 6;

console.log(output, guessNumber(n));
