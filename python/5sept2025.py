#2749. Minimum Operations to Make the Integer Zero
#time complexity...O(60)==O(1)
#space complexity...O(1)

class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for x in range(1, 61):  # loop from 1 to 60 inclusive
            rem = num1 - x * num2
            if rem < x:
                return -1
            # Python 3.8+: int.bit_count() gives the popcount
            if x >= rem.bit_count():
                return x
        return -1
        