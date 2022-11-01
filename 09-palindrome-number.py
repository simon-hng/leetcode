import math

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x < 0 or (x % 10 == 0 and x != 0)): return False

        right = 0;
        while(x > right):
            right = (right * 10) + (x % 10)
            x = math.floor(x/10)

        print(right)
        print(x)
        return x == right or x == math.floor(right / 10)

def main():
    sol = Solution();
    print(sol.isPalindrome(121))

if (__name__ == "__main__"):
    main()

