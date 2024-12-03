import math

class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        if (len(nums) == 1): 
            return 0 if target <= nums[0] else 1

        mid = math.floor(len(nums) / 2)

        if (nums[mid] > target): 
            return self.searchInsert(nums[:mid], target)
        else: 
            return self.searchInsert(nums[mid:], target) + mid

sol = Solution()
print(sol.searchInsert([1,3,5,6], 0))

