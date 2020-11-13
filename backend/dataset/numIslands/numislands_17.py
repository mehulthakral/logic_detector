class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid: return 0
        
        directions = ((1, 0), (-1, 0), (0, 1), (0, -1))
        rows = len(grid)
        cols = len(grid[0])
        
        cnt = 0
        
        for row in range(rows):
            for col in range(cols):
			    # If we find a location on an island start our BFS of that island.
                if grid[row][col] == '1':
				    # Update our count and add the starting location to the deque.
                    cnt += 1
                    q = collections.deque([])
                    q.append((row, col))
					# While we have valid island locations to process:
                    while q:
					    # Take the next location from the deque.
                        location = q.popleft()
                        r, c = location[0], location[1]
						# Search the possible adjacent directions.
                        for neigh in directions:
						    # New row and col coords to check
                            nr = r + neigh[0]
                            nc = c + neigh[-1]
							# If the new coords are valid and the lcoation is part of the island.
                            if nr >= 0 and nr < rows and nc >= 0 and nc < cols and grid[nr][nc] == '1':
							    # Update the cell value to mark it's been counted/explored.
                                grid[nr][nc] = '#'
								# Append the current location to the deque to further search it's adjacents.
                                q.append((nr, nc))
                                
        return cnt
