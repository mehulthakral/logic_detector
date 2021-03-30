class Solution {
public:
    int numIslands(vector<vector<char>>& a) {
        int count=0;
        int rows=a.size();
        if(rows==0) return 0;
        int cols=a[0].size();
        
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(a[i][j]!='2' && a[i][j]!='0')
                {
                     count +=dfs(i,j,a,rows,cols);
                     if(a[i][j]=='1')
                        a[i][j]='2';
                }
                   
            }
        }
        
        return count;
        
        
    }
    
    
    int dfs(int i,int j,vector<vector<char>>& a,int rows,int cols)
    {
      if(i>=rows || j>=cols || i<0 || j<0) 
          return 0;
        
      if(a[i][j]=='0' || a[i][j]=='2')
          return 0;
      
      
      if(i>=0 && j>=0 && i<rows && j<cols)
          if(a[i][j]=='1')
                a[i][j]='2';
        
      int ans=dfs(i+1,j,a,rows,cols) + dfs(i,j+1,a,rows,cols) + dfs(i-1,j,a,rows,cols) + dfs(i,j-1,a,rows,cols);
      
      return 1 ;  
        
    }
    
    
};
