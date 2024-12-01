class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        result = ""
        for i in range(min([len(s) for s in strs])):
            current = strs[0][i]

            if (not all([s[i] == current for s in strs])): break
            else: result += current

        return result;
                

        
