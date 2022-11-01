import math
class Solution:
    def naiveSqrt(self, x: int) -> int:
        for i in range(x + 1, 0, -1):
            if (i * i <= x): return (i)
        return 0

    def mySqrt(self, x: int) -> int:
        low = 1; high = x

        while True:
            m = (low + high) // 2
            if m * m <= x < (m + 1) * (m + 1): return m

            if m * m > x: high = m
            else: low = m

sol = Solution()
        
n = 1000 
a = list(map(
    lambda x,y: x == y,
    [sol.mySqrt(x) for x in range(n)],
    [math.floor(math.sqrt(x)) for x in range(n)]
))

print("all result from 0 to " + str(n) + " are equal: " + str(all(a)))
