import math
class Solution:
    def mySqrt(self, x: int) -> int:
        for i in range(x + 1, 0, -1):
            if (i * i <= x): return (i)
        return 0

sol = Solution()
        
n = 1000
a = list(map(
    lambda x,y: x == y,
    [sol.mySqrt(x) for x in range(n)],
    [math.floor(math.sqrt(x)) for x in range(n)]
))

print("all result from 0 to " + str(n) + " are equal: " + str(all(a)))
