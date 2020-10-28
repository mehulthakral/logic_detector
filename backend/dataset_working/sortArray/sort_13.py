from bisect import insort_left
class Solution:
    def sortArray(self, N:list):
        L = len(N)
        for i in range(1,L): insort_left(N, N.pop(i), 0, i)
        return N
		
		
