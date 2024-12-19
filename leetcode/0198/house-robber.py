from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        memo = {}

        def rob(index: int) -> int:
            if index in memo:
                return memo[index]

            if index >= len(nums):
                return 0

            withoutRob = rob(index + 1)
            withRob = nums[index] + rob(index + 2)

            memo[index] = max(withoutRob, withRob)
            return memo[index]

        return rob(0)
