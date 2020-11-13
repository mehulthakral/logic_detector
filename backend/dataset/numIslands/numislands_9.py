# python.    code   DFS
class Solution:
    def numIslands(self, m: List[List[str]]) -> int:
        def find(m,i,j,r,c):
            if i<0 or j<0:
                return 0
            if i>r-1 or j>c-1 or m[i][j]!="1":
                return 0
            m[i][j]="2"
            
            for di,dj in [(0,-1),(0,1),(1,0),(-1,0)]:
                find(m,i+di,j+dj,r,c)
        
        
        r=len(m)
        t_i=0
        for i in range (r):
            c=len(m[i])
            for j in range(c):
                if m[i][j]=='1':
                    find(m,i,j,r,c)
                    t_i+=1
        return t_i

