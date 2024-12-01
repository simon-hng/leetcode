class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        tokens = s.split(' ')

        for token in reversed(tokens):
            if token != '': return len(token)

        return 0

sol = Solution()
print(sol.lengthOfLastWord("   fly me   to   the moon  "))
        
