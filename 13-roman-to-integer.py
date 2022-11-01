class Solution:
    def romanToInt(self, s: str) -> int:
        result = 0

        substracted = {'IV': 4,  'IX': 9,
                       'XL': 40, 'XC': 90,
                       'CD': 400, 'CM': 900}
        
        normal = {'I' : 1,
                  'V' : 5,
                  'X' : 10,
                  'L' : 50,
                  'C' : 100,
                  'D' : 500,
                  'M' : 1000}

        skipnext = False
        for i in range(len(s)):
            if (skipnext):
                skipnext = False
                continue

            if (i < (len(s) - 1) and (s[i] + s[i + 1]) in substracted):
                result += substracted[s[i] + s[i + 1]]
                skipnext = True
            else:
                result += normal[s[i]]

        return result

def main():
    sol = Solution()
    print(sol.romanToInt("MCMXCIV"))

if __name__ == "__main__":
    main()

