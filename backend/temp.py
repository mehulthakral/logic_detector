from typing import List, Set, Dict, Tuple, Optional
def f(l:list):
	return min(l)

def g(l:list):
	m=l[0]
	for i in l:
		m=min(m,i)
	return m

def k(l:list):
	m=l[0]
	M=min
	for i in l:
		m=M(m,i)
	return m

def h(l:list):
	m=l[0]
	for i in l:
		if m>i:
			m=i
	return m