#3027.Find the Number of Ways to Place People II
#time complexity...O(n^2)
#space complexity...O(1)

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        ans = 0
        
        # Sort: x ascending; if tie, y descending
        points.sort(key=lambda p: (p[0], -p[1]))
        
        n = len(points)
        for i in range(n):
            yi = points[i][1]
            max_y = float('-inf')
            for j in range(i + 1, n):
                yj = points[j][1]
                if max_y < yj <= yi:
                    ans += 1
                    max_y = yj
        return ans
        