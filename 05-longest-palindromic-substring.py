# TODO: Too inefficient
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <= 1: return s

        current = ''
        for i in range(len(s), 0, -1):
            current = s[:i]

            if current == current[::-1]:
                break;

        if(len(current) >= len(s)): return current;

        next = self.longestPalindrome(s[1:])
        return current if len(current) > len(next) else next

sol = Solution()
print(sol.longestPalindrome("cbbd"))
