# Union-Find based solution
# Time complexity - O(m*n) to traverse through the entire grid | Space complexity - O(m*n) as required by UnionFind data-structure where m=number of rows, n=number of cols
class UnionFind:
    # This step will initialize the parent and rank arrays of the UnionFind data-structure and set number of islands equal to the number of 1s encountered in the grid. 
    # It'll also set the parent of every cell to be itself. 
    def __init__(self, grid):
        self.rows,self.cols = len(grid),len(grid[0])
        self.parent = [-1 for _ in range(self.rows*self.cols)]
        self.rank = [0 for _ in range(self.rows*self.cols)]
        self.numofislands=0
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j]=='1':
                    self.parent[i*self.cols+j]=i*self.cols+j
                    self.numofislands+=1
        
    # Recursively find the parent of given element until you reach the root (that is when parent[x]=x). 
    # Keep setting parent of all intermediate cells to be equal to the cell of the root of the parent. 
    # Note that this is the path-compression step which reduces the find operation's time complexity to amortized O(logn).
    def find(self,x):
        if self.parent[x]!=x:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    # For any two cells (coordinates are their corresponding 1d coordinates), union both the cells if they're connected to the same root. 
    # Else don't union the two components. 
    def union(self,x,y):
        # Find the roots of x and y cells (components).
        rootx,rooty=self.find(x),self.find(y)
        # If both of the cells belong to different components then union them. That is, set one to be parent of other based on their ranks. 
        if rootx!=rooty:
            # If rank (weight) of x's root is higher than that of y's root, then set parent of y to be x. 
            if self.rank[rootx]>self.rank[rooty]:
                self.parent[rooty]=rootx
            # Similarly if rank (weight) of y's root is higher than that of x's root, then set parent of x to be y.
            elif self.rank[rooty]>self.rank[rootx]:
                self.parent[rootx]=rooty
            # Else if both have the same rank (weight) then set parent of y to be x (could also be vice-versa) 
            # and increment the rank of this new component by 1.
            else:
                self.rank[rootx]+=1
                self.parent[rooty]=self.parent[rootx]
            # Decrement the number of islands by 1 every time we union two different cells with value==1
            self.numofislands-=1
    
            
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows,cols=len(grid),len(grid[0])
        
        # Initialize the UnionFind data-structure with the current grid. 
        # This step will initialize the parent and rank arrays of the UnionFind data-structure and set number of islands equal to the number of 1s encountered in the grid. 
        # It'll also set the parent of every cell to be itself. 
        uf = UnionFind(grid)
        
        for i in range(rows):
            for j in range(cols):
                if grid[i][j]=='1':
                    for d in [(1,0),(0,1),(-1,0),(0,-1)]:
                        ii,jj=i+d[0],j+d[1]
                        if 0<=ii<rows and 0<=jj<cols and grid[ii][jj]=='1':
                            x,y=i*cols+j,ii*cols+jj
                            uf.union(x,y)
                            
        return uf.numofislands
