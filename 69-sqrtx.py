class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x):
            if (i * i >= x): return i
        return 0

sol = Solution()
print([(sol.mySqrt(x), x) for x in range(10)])
        
