from typing import List, Callable

class Solution:
    def numIslands(self, treasureMap: List[List[str]]) -> int:
        # O(m * n) time and O(m * n) space to store the recursive stackframe calls
        m = len(treasureMap)
        if m == 0: return 0  # dead men tell no tales
        n = len(treasureMap[0])
        if n == 0: return 0  # dead men tell no tales
        num_islands = 0

        sail_down:  Traverser = lambda row, col: findTreasure(row + 1, col, treasureMap)
        sail_up:    Traverser = lambda row, col: findTreasure(row - 1, col, treasureMap)
        sail_right: Traverser = lambda row, col: findTreasure(row, col + 1, treasureMap)
        sail_left:  Traverser = lambda row, col: findTreasure(row, col - 1, treasureMap)

        land_down:  CrowsNestNavigator  = lambda row, col: (row + 1) < m  and treasureMap[row + 1][col] == "1"
        land_up:    CrowsNestNavigator  = lambda row, col: (row - 1) > -1 and treasureMap[row - 1][col] == "1"
        land_right: CrowsNestNavigator  = lambda row, col: (col + 1) < n  and treasureMap[row][col + 1] == "1"
        land_left:  CrowsNestNavigator  = lambda row, col: (col - 1) > -1 and treasureMap[row][col - 1] == "1"

        def findTreasure(row: int, col: int, grid: List[List[str]]) -> None:
            nonlocal m, n
            grid[row][col] = "x"
            # for each landpiece, attempt to go left, right, up or down if there is land
            if land_down(row, col):  sail_down(row, col)
            if land_up(row, col):    sail_up(row, col)
            if land_right(row, col): sail_right(row, col)
            if land_left(row, col):  sail_left(row, col)

        for col in range(n):
            for row in range(m):
                if treasureMap[row][col] == "1":
                    findTreasure(row, col, treasureMap)
                    num_islands += 1

        return num_islands
