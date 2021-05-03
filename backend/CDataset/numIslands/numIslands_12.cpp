class Solution {
public:
    vector<int> parent,size;
    int dis[5]={1,0,-1,0,1};
    int cou;
    int find_set(int v)
    {
        if(parent[v]==v) return v;
        return parent[v]=find_set(parent[v]);
    }
    void make_set(int v)
    {
        parent[v]=v;
        size[v]=1;
    }
    void union_set(int a,int b)
    {
        a=find_set(a);
        b=find_set(b);
        if(a!=b) 
        {cou--;
         if(a<b) swap(a,b);
         parent[b]=a;
         size[a]+=size[b];
        }
            
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        int n=grid.size(),m=grid[0].size();
        parent.resize(n*m);
        size.resize(n*m,0);
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                {   
                    cou++;
                    make_set(i*m+j);
                }
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
                if(grid[i][j]=='1')
                {  
                 for(int k=0;k<4;k++)
                 {
                     int dx=i+dis[k],dy=j+dis[k+1];
                     if(dx>=0&&dx<n&&dy>=0&&dy<m&&grid[dx][dy]=='1')
                         union_set(i*m+j,dx*m+dy);
                 }
                }
        return cou;
    }
};
