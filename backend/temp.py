def SORT(N:list):
	L = len(N)
	return [N.pop(min(range(L-i), key = lambda x: N[x])) for i in range(L)]