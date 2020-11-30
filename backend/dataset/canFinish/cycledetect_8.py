import collections
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        ## RC ##
        ## APPROACH : DFS ##
        ## LOGIC: DETECT CYCLE IN DIRECTED GRAPH. ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##

        # DFS function will return False when a cycle is detected else returns True. (at one particular node)
        def hasCycle(node):
            
            if(node in exploring):                     # Cycle detected. If you are still exploring and found the same element again in exploring.
                return True
            
            if(node in explored):                       
                return False

            exploring.add(node)                         # mark this node as visited.
                                                         
            for nei in graph[node]:                     # visit all neigbhors of this node.
                if( hasCycle(nei) ):
                    return True                         # if one of its child has cycle return from function call
            
            explored.add(node)
            exploring.remove(node)
            
            return False
        
        graph = collections.defaultdict(list)
        for u,v in prerequisites:
            graph[u].append(v)
        explored = set()                                 # To keep track of explored nodes in the graph
        exploring = set()                                # still in exploring, not yet finished.
        
        for node in list(graph):                         # watch out => list(graph)
            if(node not in explored):
                if(hasCycle(node)):         
                    return False
        return True
        
        ## APPROACH : BFS ##
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##
        graph = collections.defaultdict(list)
        in_degree = collections.defaultdict(int)
        for u,v in prerequisites:
            graph[u].append(v)
            in_degree[v] += 1

        # init queue with indegree 0 nodes
        queue = collections.deque([ u for u in range(0, numCourses) if u not in in_degree])

        count = 0
        while(queue):
            size = len(queue)
            for _ in range(size):
                node = queue.popleft()
                count += 1
                for nei in graph[node]:
                    in_degree[nei] -= 1

                    if in_degree[nei] == 0:
                        queue.append( nei )
        return count == numCourses      # check if all courses are completed
        
