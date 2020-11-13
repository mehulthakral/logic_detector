class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        rows_count = len(grid)
        cols_count = len(grid[0]) if grid else 0
        num_islands = 0
        stack = []
        for i in range(rows_count):
            for j in range(cols_count):
                if grid[i][j] == '1':
                    num_islands += 1
                    stack.append((i, j))
                    while stack:
                        ci, cj = stack.pop()
                        grid[ci][cj] = '0'

                        if ci > 0 and grid[ci - 1][cj] == '1':
                            stack.append((ci - 1, cj))

                        if ci < rows_count - 1 and grid[ci + 1][cj] == '1':
                            stack.append((ci + 1, cj))

                        if cj > 0 and grid[ci][cj - 1] == '1':
                            stack.append((ci, cj - 1))

                        if cj < cols_count - 1 and grid[ci][cj + 1] == '1':
                            stack.append((ci, cj + 1))

        return num_islands
