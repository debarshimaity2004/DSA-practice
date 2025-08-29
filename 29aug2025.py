#3021. Alice and Bob Playing Flower Game
#time complexity...O(1)
#space complexity...O(1)

class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        even_n, odd_n = n // 2, (n + 1) // 2
        even_m, odd_m = m // 2, (m + 1) // 2
        return even_n * odd_m + odd_n * even_m
    

