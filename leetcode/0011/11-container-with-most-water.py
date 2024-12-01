class Solution:
    def maxArea(self, heights: list[int]) -> int:
        result = min(heights[0], heights[1])
        l = 0
        r = len(heights) - 1

        while (l < r):
            current = min(heights[l], heights[r]) * (r - l)
            result = max(current, result)

            if (heights[l] < heights[r]):
                l += 1
            else:
                r -= 1

        return result


sol = Solution()
result = sol.maxArea([4, 3, 2, 1, 4])
print(result)
