class Solution:
    def convert(self, s: str, numRows: int) -> str:
        result: list[str] = [''] * numRows
        current = 0;

        if (numRows == 1): return s

        while current < len(s):
            for i in range(numRows - 1):
                if (current >= len(s)): break

                result[i] += s[current]
                current += 1
            for i in range(numRows - 1, 0, -1):
                if (current >= len(s)): break

                result[i] += s[current]
                current += 1

        return ''.join(result)

sol = Solution()
print(sol.convert("PAYPALISHIRING", 4))
