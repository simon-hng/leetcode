from typing import List


class Solution:
    def findMedianSortedArrays(self,
                               nums1: List[int],
                               nums2: List[int]) -> float:
        n = 0
        m = 0
        merged = []
        for i in range(len(nums1) + len(nums2)):
            if n < len(nums1) and m < len(nums2):
                if (nums1[n] < nums2[m]):
                    merged.append(nums1[n])
                    n += 1
                else:
                    merged.append(nums2[m])
                    m += 1
            elif n < len(nums1):
                merged.append(nums1[n])
                n += 1
            else:
                merged.append(nums2[m])
                m += 1

        print(merged)

        mid = len(merged) // 2
        if len(merged) % 2 == 0:
            return float(merged[mid]
                         + merged[mid - 1]) / 2

        return merged[mid]


sol = Solution()
sol.findMedianSortedArrays([1, 3], [2])
