class Solution:
    def __init__(self):
        self.vis = [[]]
        self.rank = [[]]

    def parent(self,i,j,pvec):
        if pvec[i][j]==(i,j):
            return i,j
        pvec[i][j] = self.parent(pvec[i][j][0],pvec[i][j][1],pvec)
        return pvec[i][j]

    def union(self,i1,j1,i2,j2):
        pvec = self.vis
        rank = self.rank
        ii1,jj1 = self.parent(i1,j1,pvec)
        ii2,jj2 = self.parent(i2,j2,pvec)
        if ii1 == ii2 and jj1 == jj2:
            return
        if rank[ii1][jj1] < rank[ii2][jj2]:
            pvec[ii1][jj1] = (ii2,jj2)
        elif rank[ii1][jj1] > rank[ii2][jj2]:
            pvec[ii2][jj2] = (ii1,jj1)
        else:
            pvec[ii1][jj1] = (ii2,jj2)
            rank[ii2][jj2]+=1
        return

    def numIslands(self, grid: List[List[str]]) -> int:
        n = len(grid)
        if n <1:
            return 0
        
        m = len(grid[0])
        if n == 1:
            if m < 1:
                return 0
            if m == 1:
                if grid[0][0] == '1':
                    return 1
                return 0

        self.vis = [[(j,i) for i in range(m)] for j in range(n)]
        self.rank = [[0 for i in range(m)] for j in range(n)]
        vis = self.vis
        for i in range(n):
            for j in range(m):
                par = 0
                if grid[i][j] == '1':
                    if i > 0 and not par:
                        if grid[i-1][j] == '1':
                            self.union(i,j,i-1,j)
                    if i < n-1 and not par:
                        if grid[i+1][j] == '1':
                            self.union(i,j,i+1,j)
                    if j > 0 and not par:
                        if grid[i][j-1] == '1':
                            self.union(i,j,i,j-1)
                    if j < m-1 and not par:
                        if grid[i][j+1] == '1':
                            self.union(i,j,i,j+1)
        
        freq = [[0 for i in range(m)] for j in range(n)]
        res = 0
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    setx, sety = self.parent(i,j,vis)
                    if not freq[setx][sety]:
                        res+=1
                    freq[setx][sety]+=1
        return res
