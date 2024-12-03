from typing import Dict


class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        char_to_count: Dict[str, int] = {}

        for c in magazine:
            if c in char_to_count:
                char_to_count[c] += 1
            else:
                char_to_count[c] = 1

        for c in ransomNote:
            if c in char_to_count and char_to_count[c] > 0:
                char_to_count[c] -= 1
            else:
                return False

        return True
