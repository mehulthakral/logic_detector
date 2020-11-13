from collections import Counter
class Solution:
    def sortArray(self, N:list):
        C, m, M, S = Counter(N), min(N), max(N), []
        for n in range(m,M+1): S.extend([n]*C[n])
        return S
		
		
