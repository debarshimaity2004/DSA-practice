#earliest time to finsih one task
#tc.. O(n)
#sc.. O(1)

class Solution:
    def earliestTime(self, tasks: List[List[int]]) -> int:
        n=len(tasks)
        earliest=float('inf')
        for i in range(n):
            if tasks[i][0]+tasks[i][1]<earliest:
                earliest=tasks[i][0]+tasks[i][1]
        return earliest