class Solution:
    def climbStairs(self, n: int) -> int:
        return self.climbStairsMemo(n, {})
        
    def climbStairsMemo(self, n: int, memo) -> int:
        if (n in memo): 
            print(memo)
            return memo[n]

        if (n < 0): return 0;
        if (n == 0 or n == 1): return 1

        memo[n] = self.climbStairsMemo(n - 1, memo) + self.climbStairsMemo(n - 2, memo)
        return memo[n]
