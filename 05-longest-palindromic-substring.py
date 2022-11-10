# TODO: Too inefficient
class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        for i in range(len(s)):
            l = i if len(s) % 2 != 0 else i - 1
            r = i

            while (l > 0 and r < len(s)):
                if (l != r): 
                    if (r - l > len(result)):
                        result = s[l:r+1]
                l-=1; r+=1

        return result


sol = Solution()
print(sol.longestPalindrome("aa"))
