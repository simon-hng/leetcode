from typing import List, Dict


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        num_to_count: Dict[int, int] = {}

        for num in nums:
            if num not in num_to_count:
                num_to_count[num] = 1
            else:
                num_to_count[num] += 1

            if num_to_count[num] > len(nums) // 2:
                return num

        return 0
