class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return "{0:b}".format(int(a, 2) + int(b, 2))

sol = Solution()
result = sol.addBinary("11" ,"1")
print(result)
        
