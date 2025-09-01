#1792. Maximum Average Pass Ratio
#time complexity...O(N+K∗Log(N)), where n=no of classes and k=no of extra student
#space complexity...O(N)

class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        # Function to calculate gain
        def gain(p, t):
            return (p + 1) / (t + 1) - (p / t)

        # Max heap (store negative for max-heap behavior)
        pq = [(-gain(p, t), p, t) for p, t in classes]
        heapq.heapify(pq)

        # Allocate extra students
        for _ in range(extraStudents):
            g, p, t = heapq.heappop(pq)
            p, t = p + 1, t + 1
            heapq.heappush(pq, (-gain(p, t), p, t))

        # Compute final average
        total = 0
        for _, p, t in pq:
            total += p / t
        return total / len(classes)
        