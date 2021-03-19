from typing import List
from dataset_server import TreeNode
import collections
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        ## RC ##
        ## APPROACH : BFS ##
        
		## TIME COMPLEXITY : O(N) ##
		## SPACE COMPLEXITY : O(N) ##

        if(not root):   return []
        queue = collections.deque([root])
        all_levels = []
        while (queue): 
            size = len(queue)
            curr_level = []
            for _ in range(size):
                curr = queue.popleft()
                curr_level.append(curr.val)
                if(curr.left):     queue.append(curr.left)
                if(curr.right):    queue.append(curr.right)
            all_levels.append(curr_level)
        return all_levels
    
        ## RECURSIVE APPROACH ##
        if not root:    return []
        levels = collections.defaultdict(list)
        def helper(node, level):
            levels[level].append(node.val)
            if node.left:   helper(node.left, level + 1)
            if node.right:  helper(node.right, level + 1)
        helper(root, 0)
        return levels.values()
