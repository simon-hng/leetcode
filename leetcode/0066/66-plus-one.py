class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        result = str(int(''.join(str(digit) for digit in digits)) + 1)
        return [str(r) for r in [*result]]
