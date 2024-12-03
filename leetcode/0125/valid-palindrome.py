class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = ''.join([c for c in s.lower() if c.isalnum()])

        left = 0
        right = len(s) - 1

        while (left <= right):
            if s[left] != s[right]:
                return False

            left += 1
            right -= 1

        return True


sol = Solution()

print(sol.isPalindrome("A man, a plan, a canal: Panama"))
