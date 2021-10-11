function my_answer(nums) {
	for (let i = 1; i < nums.length; i++) {
		/* 해당 인덱스가 가질 수 있는 최대값을 구하려면 */
		/* 이전 인덱스에 있는 값이 양수여야 함 */
		if (nums[i - 1] > 0)
			nums[i] += nums[i - 1];
	}
	/* 최대값 리턴 */
	return Math.max(...nums);
};

input = [
	[-2,1,-3,4,-1,2,1,-5,4],
	[1],
	[5,4,-1,7,8]
]

output = [
	6,
	1,
	23
]

for (let i = 0; i < input.length; i++) {
	console.log("input:", input[i], "got:", my_answer(input[i]), "want:", output[i]);
}
