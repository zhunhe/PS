/*
** 1. Two Sum
** https://leetcode.com/problems/two-sum/
*/

import Foundation

class Solution {
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        for i in nums.indices {
            for j in nums.indices {
                if i != j && nums[i] + nums[j] == target {
                    return [i, j]                
                }
            }
        }
        return []
    }
}

let solution = Solution()

let nums = [2, 7, 11, 15]
let target = 9
let result = solution.twoSum(nums, target)
let expected = [0, 1]
if (result == expected) {
    print("correct!")
} else {
    print("wrong! result:", result, "expected:", expected)
}
