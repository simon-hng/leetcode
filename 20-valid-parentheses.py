class Solution:
    def isValid(self, s: str) -> bool:
        parens = {'{':'}', '(':')', '[':']'}
        stack = []

        for char in s:
            if char in parens:
                stack.append(char)
            elif (len(stack) != 0 and parens[stack[len(stack) - 1]] == char):
                stack.pop()
            else: return False

        return len(stack) == 0
            
        
