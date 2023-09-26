from typing import Set, Dict, List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        col: Dict[int, Set] = {key: set() for key in range(0, 9)}
        box: Dict[int, Set] = {key: set() for key in range(0, 9)}
        for row_index in range(0, 9):
            row = set()
            for col_index in range(0, 9):
                current_box = box[row_index//3 + (col_index//3) * 3]
                current_field = board[row_index][col_index]

                if (current_field == "."):
                    continue
                if (current_field in col[col_index]
                        or current_field in row
                        or current_field in current_box):
                    return False

                row.add(current_field)
                col[col_index].add(current_field)
                current_box.add(current_field)

        return True
