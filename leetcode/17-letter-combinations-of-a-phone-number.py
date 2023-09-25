from typing import List


class Solution:

    def letterCombinations(self, digits: str) -> List[str]:
        dic = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        if not digits:
            return []

        prefixes = list(dic[digits[0]])
        if len(digits) == 1:
            return prefixes

        postfixes = self.letterCombinations(digits[1:])
        return [prefix + postfix
                for postfix in postfixes
                for prefix in prefixes]


sol = Solution()
print(sol.letterCombinations("23"))
