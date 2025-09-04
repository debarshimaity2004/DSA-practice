#3516. Find Closest Person
#time complexity...O(1)
#space complexity...O(1)

class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        dist_x = abs(x - z)
        dist_y = abs(y - z)
        if dist_x == dist_y:
            return 0
        return 1 if dist_x < dist_y else 2
        