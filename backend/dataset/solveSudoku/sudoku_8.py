from typing import List, List
import collections
import itertools
class Solution:
    def solveSudoku(self, B: List[List[str]]) -> None:
    	N, S = range(9), list('123456789')
    	R, C, T, V = {i:set() for i in N}, {i:set() for i in N}, {i:set() for i in N}, collections.deque()
    	for i,j in itertools.product(N,N):
    		if B[i][j] != ".": R[i].add(B[i][j]), C[j].add(B[i][j]), T[3*(i//3)+j//3].add(B[i][j])
    		else: V.append((i,j))
    	def dfs():
    		if not V: return True
    		i, j, t = V[0][0], V[0][1], 3*(V[0][0]//3)+V[0][1]//3
    		for n in S:
    			if n not in R[i]|C[j]|T[t]:
    				B[i][j], _ = n, [R[i].add(n), C[j].add(n), T[t].add(n), V.popleft()]
    				if dfs(): return True
    				else: B[i][j], _ = '.', [R[i].discard(n), C[j].discard(n), T[t].discard(n), V.appendleft((i,j))]
    		return False
    	dfs()