from typing import List


class Solution:
    def floodFill(self, image: List[List[int]],
                  sr: int, sc: int, color: int) -> List[List[int]]:
        # By constraint sr, sc valid here
        self.floodFillStep(image, sr, sc, color, image[sr][sc])

        return image

    def floodFillStep(self, image: List[List[int]],
                      sr: int, sc: int, color: int,
                      startColor: int):
        if sr < 0 or sr >= len(image):
            return image
        if sc < 0 or sc >= len(image[0]):
            return image
        if image[sr][sc] != startColor or image[sr][sc] == color:
            return image

        image[sr][sc] = color

        self.floodFillStep(image, sr + 1, sc, color, startColor)
        self.floodFillStep(image, sr - 1, sc, color, startColor)
        self.floodFillStep(image, sr, sc + 1, color, startColor)
        self.floodFillStep(image, sr, sc - 1, color, startColor)


sol = Solution()
image = [[1, 1, 1], [1, 1, 0], [1, 0, 1]]
print(sol.floodFill(image, 1, 1, 2))
