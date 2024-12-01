from itertools import combinations

class Solution:
    def threeSumNaive(self, nums: list[int]) -> list[list[int]]:
        result = set([])

        for i in range(len(nums)):
            for j in range(len(nums)):
                for k in range(len(nums)):
                    if (i != j and j != k and k != i and nums[i] + nums[j] + nums[k] == 0):
                        result.add(tuple(sorted([nums[i], nums[j], nums[k]])))

        return list(result)

    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result = set()

        ns = []; ps = []; zs = []
        for num in nums:
            if num < 0:     ns.append(num)
            elif num == 0:  zs.append(num)
            else:           ps.append(num)

        Ns = set(ns); Ps = set(ps)

        # [-1, 0, 1]
        if zs: 
            result = result.union(set(([tuple([-p, 0, p])
                        for p in Ps 
                        if -p in Ns])))

        # [0, 0, 0]
        if len(zs) >= 3: 
            result.add(tuple([0, 0, 0]))

        result = result.union(set([tuple(sorted([x,y, -(x + y)])) 
                    for (x,y) 
                    in combinations(ns, 2) 
                    if -(x + y) in Ps]))

        result = result.union(set([tuple(sorted([x,y, -(x + y)])) 
                    for (x,y) 
                    in combinations(ps, 2) 
                    if -(x + y) in Ns]))
        
        return [list(r) for r in result]

            



sol = Solution()
print(sol.threeSum([-1,0,1,2,-1,-4]))

