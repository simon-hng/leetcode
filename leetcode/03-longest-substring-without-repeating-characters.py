from typing import Dict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0

        char_to_idx: Dict[str, int] = {}
        start = 0
        result = 0

        for i, character in enumerate(s):
            if character in char_to_idx:
                start = max(start, char_to_idx[character] + 1)
            char_to_idx[character] = i
            result = max(result, i - start + 1)

        return result
