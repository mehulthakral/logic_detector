def f(l:list):
	m=l[0]
	for i in l:
		if i>m:
			m=i
	return m

def g(l:list):
	m=l[0]
	for i in l:
		if i<m:
			m=i
	return m
			