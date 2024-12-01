from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        def step(current: str, open_brackets: int, depth) -> List[str]:
            if depth == 1 and open_brackets == 0:
                return [current]
            if open_brackets > depth:
                return []
            if open_brackets <= 0:
                return step(current + "(", open_brackets + 1, depth-1)

            return step(current + "(", open_brackets + 1, depth-1) \
                + step(current + ")", open_brackets - 1, depth-1)

        return step("(", 1, n * 2)


sol = Solution()

print(sol.generateParenthesis(3))
