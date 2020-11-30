from collections import defaultdict
class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        pre = defaultdict(list)
        count = {}
        
        for i in prerequisites:
            pre[i[1]].append(i[0])
            count[i[0]]=count.get(i[0],0) + 1
            
        queue = []
        for i in range(numCourses):
            if i not in count:
                queue.append(i)
        solution_count = 0       
        while len(queue):
            solution_count +=1
            x = queue.pop(0)
            for n in pre[x]:
                count[n] -= 1
                if count[n] == 0:
                    del count[n]
                    queue.append(n)
        
        if solution_count == numCourses:
            return True
        return False
