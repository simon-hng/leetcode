class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if (len(s) == 0): return 0
        
        contained = set()
        result = 0

        for element in s:
            if (element in contained): break;

            result += 1;
            contained.add(element)

        return max(self.lengthOfLongestSubstring(s[1:]), result)

def main():
    sol =  Solution();
    print(sol.lengthOfLongestSubstring("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"))

if (__name__ == "__main__"):
    main()

