def bfs(self, grid, dictionary, tup):
    if tup not in dictionary and grid[tup[0]][tup[1]] == "1":
        dictionary[tup] = tup
        if tup[0] > 0:
            tup2 = (tup[0] -1, tup[1])
            bfs(self, grid, dictionary, tup2)
        if tup[1] > 0:
            tup2 = (tup[0], tup[1] -1)
            bfs(self, grid, dictionary, tup2)
        if tup[0] < len(grid)-1:
            tup2 = (tup[0] +1, tup[1])
            bfs(self, grid, dictionary, tup2)
        if tup[1] < len(grid[0])-1:
            tup2 = (tup[0],tup[1] +1)
            bfs(self, grid, dictionary, tup2)


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if grid != None and len(grid) != 0:
            dictionary = {}
            islands = 0
            for i in range(len(grid)):
                for j in range(len(grid[0])):
                    tup = (i,j)
                    if grid[i][j] == "1" and tup not in dictionary:
                        islands += 1
                        bfs(self, grid, dictionary, tup)
            return islands 
        else:
            return 0
