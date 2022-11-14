class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""

        for i in range(len(s)):
            l = i; r = i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > len(result):
                    result = s[l: r+1]
                l -= 1; r += 1

            l = i; r = i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if (r - l + 1) > len(result):
                    result = s[l: r+1]
                l -= 1; r += 1

        return result

sol = Solution()
print(sol.longestPalindrome("aba"))
