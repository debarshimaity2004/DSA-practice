#3446. Sort Matrix by Diagonals
#time complexity...O(N^2 *logN)
#space complexity...O(N^2)

class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        n = len(grid)

        # diagonals starting from first column (descending)
        for i in range(n):
            vec = [grid[i+j][j] for j in range(n-i)]
            vec.sort(reverse=True)
            for j in range(n-i):
                grid[i+j][j] = vec[j]

        # diagonals starting from first row (ascending)
        for j in range(1, n):
            vec = [grid[i][j+i] for i in range(n-j)]
            vec.sort()
            for i in range(n-j):
                grid[i][j+i] = vec[i]

        return grid