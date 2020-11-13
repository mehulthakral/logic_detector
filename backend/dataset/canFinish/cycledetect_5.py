class Solution:
    
    def makeEdgeList(self,prerequisites):
        prereq = {}
        for prereuisite in prerequisites:
            prereq[prereuisite[1]] = prereq.get(prereuisite[1],[])+[prereuisite[0]]
            prereq[prereuisite[0]] = prereq.get(prereuisite[0],[])
        return prereq
    
    def calculateIndegree(self,edgelist):
        indegree = [0]*len(edgelist)
        vertex2id = dict((i,j) for j,i in enumerate(edgelist))
        zero_indegree = set(list(edgelist))
        for prereq in edgelist:
            for pre in edgelist[prereq]:
                indegree[vertex2id[pre]]+=1
                zero_indegree.discard(pre)
        return indegree,vertex2id,zero_indegree
                
        
    
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        if len(prerequisites)==0:
            return True
        prerequisite = self.makeEdgeList(prerequisites)
        indegree,vertex2id,zero_indegree = self.calculateIndegree(prerequisite)
        count = 0
        Q = list(zero_indegree)
        while Q:
            course = Q.pop(0)
            count+=1
            prereq = prerequisite[course]
            for p in prereq:
                indegree[vertex2id[p]]-=1
                if indegree[vertex2id[p]]==0:
                    Q.append(p)
                    
        if count ==len(prerequisite):
            return True
        else:
            return False
        
