#37. Sudoku Solver
#time complexity...O(9^M)
#space complexity...O(M)

class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        """
        Optimized Sudoku Solver using backtracking + bitmasks.
        Modifies board in-place.
        """
        # bitmask for rows, cols, and boxes
        row_mask = [0] * 9
        col_mask = [0] * 9
        box_mask = [0] * 9
        empty_cells = []

        def box_index(r, c):
            return (r // 3) * 3 + (c // 3)

        # Pre-fill masks and record empty cells
        for i in range(9):
            for j in range(9):
                if board[i][j] == ".":
                    empty_cells.append((i, j))
                else:
                    num = int(board[i][j])
                    bit = 1 << num
                    row_mask[i] |= bit
                    col_mask[j] |= bit
                    box_mask[box_index(i, j)] |= bit

        def backtrack(idx=0):
            if idx == len(empty_cells):
                return True  # all filled

            r, c = empty_cells[idx]
            b = box_index(r, c)

            # get all candidate numbers (1–9)
            used = row_mask[r] | col_mask[c] | box_mask[b]
            for num in range(1, 10):
                bit = 1 << num
                if used & bit:  # already used
                    continue
                # place number
                board[r][c] = str(num)
                row_mask[r] |= bit
                col_mask[c] |= bit
                box_mask[b] |= bit

                if backtrack(idx + 1):
                    return True

                # undo
                board[r][c] = "."
                row_mask[r] ^= bit
                col_mask[c] ^= bit
                box_mask[b] ^= bit

            return False

        backtrack()
