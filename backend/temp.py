from typing import List, Set, Dict, Tuple, Optional
def bubbleSort(arr:list): 
    n = len(arr) 
  
    # Traverse through all array elements 
    for i in range(n-1): 
    # range(n) also work but outer loop will repeat one time more than needed. 
  
        # Last i elements are already in place 
        for j in range(0, n-i-1): 
  
            # traverse the array from 0 to n-i-1 
            # Swap if the element found is greater 
            # than the next element 
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j] 
    return arr
                
def bubbleSortOptimized(arr:list): 
    n = len(arr) 
  
    # Traverse through all array elements 
    for i in range(n-1): 
    # range(n) also work but outer loop will repeat one time more than needed. 
        flag=False
        # Last i elements are already in place 
        for j in range(0, n-i-1): 
  
            # traverse the array from 0 to n-i-1 
            # Swap if the element found is greater 
            # than the next element 
            if arr[j] > arr[j+1] : 
                flag=True
                arr[j], arr[j+1] = arr[j+1], arr[j] 
        
        if flag==False:
            return arr 
    return arr

def f(l:list):
	return min(l)

def g(l:list):
	m=l[0]
	for i in l:
		m=min(m,i)
	return m