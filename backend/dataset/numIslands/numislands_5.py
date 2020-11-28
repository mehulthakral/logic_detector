class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        djs = [] # list of disjoint sets
        lbl = 0  # the label
        
        # One pass and (not very classic) union-find:
        for i in range(len(grid)):
            for j in range(len(grid[0])):
            
            # Set background to int 0.
                if grid[i][j] == '0':
                    grid[i][j] = 0
                    continue
                
            # Get neighboring labels.
                up = grid[i-1][j] if i > 0 else 0
                left = grid[i][j-1] if j > 0 else 0
                    
                # If both neighbors are 0,
                #   assign a new label to the current pixel.
                # And create a new set with only one element.
                if up == 0 and left == 0:
                    lbl += 1
                    grid[i][j] = lbl
                    djs.append({lbl})
                        
                # If only one neighbor is 0 or both neighbors are 
				#   labeled the same, assign that label to the current pixel.
                elif up == left or up == 0 or left == 0:
                    grid[i][j] = max(up,left)
                        
                # If neighbors are labeled differently,
                #   the labels should belong the same set.
                # Union those two sets and assign any of those labels.
                else:
                    uf = union(djs,up,left)
                    grid[i][j] = up
                        
        # The number of sets left in the list djs is the number of islands.    
        return len(djs)
        

def union(djs,l0,l1):
	
    # Find the indecises of the sets containing l0 and l1.
    r0, r1 = None, None; i = 0; # the indecises 
    while r0 is None or r1 is None:
        if r0 is None and l0 in djs[i]:
            r0 = i
        if r1 is None and l1 in djs[i]:
            r1 = i
        i += 1
    
    # If l0 and l1 are in the same set, return.
    if r0 == r1:
        return djs
        
    # Union those two sets.
    djs[r0] = djs[r0].union(djs[r1])
    del djs[r1]
    return djs
