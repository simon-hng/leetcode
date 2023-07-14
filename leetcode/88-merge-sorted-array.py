class Solution:

    """
    Do not return anything, modify nums1 in-place instead.
    """
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        i = m - 1; j = n - 1; k = m + n - 1

        while j >= 0:
            if i >= 0 and nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1;
            else:
                nums1[k] = nums2[j]
                j -= 1;
            k -= 1;
        
sol = Solution()
nums1 = [0, 0, 0]
nums2 = [2, 5, 6]
sol.merge(nums1, 0, nums2 , 3)
print(nums1)
