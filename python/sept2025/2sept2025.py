#3025. Find the Number of Ways to Place People I
#time complexity...O(n^2)
#space complexity...O(1)

class Solution:
    def numberOfPairs(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 0
        
        # negate y for sorting trick
        for i in range(n):
            points[i][1] = -points[i][1]
        
        points.sort()  # sorts by x asc, then y asc (since we negated y)
        
        for i in range(n):
            x, y = points[i][0], -points[i][1]
            ymax = -10**9  # bar
            for j in range(i + 1, n):
                x1, y1 = points[j][0], -points[j][1]
                if y1 > ymax and y1 <= y:
                    ans += 1
                    ymax = max(ymax, y1)
        
        return ans
        