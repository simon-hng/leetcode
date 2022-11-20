import math

class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        signed = False

        max = math.pow(2, 31) - 1
        min = math.pow(2, 31)

        if (x < 0):
            x = -x
            signed = True

        while(x > 0):
            result *= 10
            result += x % 10
            x = x // 10

            if (not signed and result > max) or (signed and result > min):
                return 0

        return result if not signed else -result

sol = Solution()
print(sol.reverse(123))

