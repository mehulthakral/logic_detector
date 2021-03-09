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

def selectionSort(arr:list):
    # i indicates how many items were sorted
    for i in range(len(arr)-1):
        # To find the minimum value of the unsorted segment
        # We first assume that the first element is the lowest
        min_index = i
        # We then use j to loop through the remaining elements
        for j in range(i+1, len(arr)-1):
            # Update the min_index if the element at j is lower than it
            if arr[j] < arr[min_index]:
                min_index = j
        # After finding the lowest item of the unsorted regions, swap with the first unsorted item
        arr[i], arr[min_index] = arr[min_index], arr[i]

def insertionSort(arr:list):
 
    # Traverse through 1 to len(arr)
    for i in range(1, len(arr)):
 
        key = arr[i]
 
        # Move elements of arr[0..i-1], that are
        # greater than key, to one position ahead
        # of their current position
        j = i-1
        while j >= 0 and key < arr[j] :
                arr[j + 1] = arr[j]
                j -= 1
        arr[j + 1] = key
    
    return arr 


def quickSort(arr:list):
    
    def partition(low, high): 
        i = (low-1)         # index of smaller element 
        pivot = arr[high]     # pivot 
    
        for j in range(low, high): 
    
            # If current element is smaller than or 
            # equal to pivot 
            if arr[j] <= pivot: 
    
                # increment index of smaller element 
                i = i+1
                arr[i], arr[j] = arr[j], arr[i] 
    
        arr[i+1], arr[high] = arr[high], arr[i+1] 
        return (i+1) 
  
  
  
    def helper(low, high): 
        if len(arr) == 1: 
            return arr 
        
        if low < high: 
    
            # pi is partitioning index, arr[p] is now 
            # at right place 
            pi = partition(low, high) 
    
            # Separately sort elements before 
            # partition and after partition 
            helper(low, pi-1) 
            helper(pi+1, high) 
    
    return arr

def mergeSort(arr:list):
    
    def helper(arr):
        
        if len(arr) > 1:
    
            # Finding the mid of the array
            mid = len(arr)//2
    
            # Dividing the array elements
            L = arr[:mid]
    
            # into 2 halves
            R = arr[mid:]
    
            # Sorting the first half
            helper(L)
    
            # Sorting the second half
            helper(R)
    
            i = j = k = 0
    
            # Copy data to temp arrays L[] and R[]
            while i < len(L) and j < len(R):
                if L[i] < R[j]:
                    arr[k] = L[i]
                    i += 1
                else:
                    arr[k] = R[j]
                    j += 1
                k += 1
    
            # Checking if any element was left
            while i < len(L):
                arr[k] = L[i]
                i += 1
                k += 1
    
            while j < len(R):
                arr[k] = R[j]
                j += 1
                k += 1
                
    helper(arr)
    
    return arr

def timSort(arr:list):
    arr.sort()
    return arr 