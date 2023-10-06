from typing import List, Dict


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        num_to_idx: Dict[int, int] = {}
        for i in range(len(nums)):
            rest = target - nums[i]
            if rest in num_to_idx:
                return [i, num_to_idx[rest]]

            num_to_idx[nums[i]] = i

        return []
