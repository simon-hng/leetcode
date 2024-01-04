class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums) + 1):
                if j == (len(nums)):
                    return i + 1
                if nums[j] > nums[i]:
                    nums[i + 1] = nums[j]
                    break
        return 0


def main():
    sol = Solution()
    arr = [1, 1, 2]
    print(sol.removeDuplicates(arr))


if __name__ == "__main__":
    main()
