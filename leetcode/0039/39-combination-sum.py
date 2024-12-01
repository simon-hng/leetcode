from typing import List


class Solution:
    def combinationSum(self,
                       candidates: List[int],
                       target: int) -> List[List[int]]:

        def step(result: list[int],
                 candidates: List[int],
                 target: int) -> List[List[int]]:
            # Accept
            if target == 0:
                return [result]

            # Reject
            if len(candidates) == 0:
                return []

            current_result: List[List[int]] = []
            for i in range(len(candidates)):
                current = candidates[i]
                next_target = target - current
                next_candidates = [
                    cand for cand in candidates[i:] if cand <= next_target]
                current_result += step(result + [current],
                                       next_candidates, target - current)

            return current_result

        return step([], candidates, target)


sol = Solution()
print(sol.combinationSum([2, 3, 6, 7], 7))
