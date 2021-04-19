class Solution {
public:
typedef struct
{
    short x;
    short y;
}POS;
    void solveSudoku(vector<vector<char> >& board) {
        solve(board);
    }
private:
    int solve(vector<vector<char> >& board) {
        vector<POS> todo;//cells not filled
        short r[9]={0,0,0,0,0,0,0,0,0};//row
        short c[9]={0,0,0,0,0,0,0,0,0};//col
        short b[9]={0,0,0,0,0,0,0,0,0};//block
        //short n[9]={0,0,0,0,0,0,0,0,0};
        short i,j;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(board[i][j]!='.')
                {
                    short temp=(1<<(board[i][j]-'1'));
                    r[i]=r[i]|temp;
                    c[j]=c[j]|temp;
                    int pos=i/3+j/3*3;
                    b[pos]=b[pos]|temp;
                    //n[board[i][j]-'1']++;
                }
                else
                {
                    POS t;
                    t.x=i;
                    t.y=j;
                    todo.push_back(t);
                }
            }
        }
        j=0;//debug
        while(todo.size()!=0)
        {
            int flag=0;
            for(auto it=todo.begin();it!=todo.end();it++)
            {
                int x=(*it).x,y=(*it).y;
                int pos=x/3+y/3*3;
                short temp=~(b[pos]|r[x]|c[y]|0xfe00);
                if(temp==0)
                {
                    return -1;
                }
                else if(((temp-1)&temp)==0)//the cell has only one valid number 
                {
                    i=0;
                    r[x]=r[x]|temp;
                    c[y]=c[y]|temp;
                    b[pos]=b[pos]|temp;
                    while(temp!=1)
                    {
                        temp=temp>>1;
                        i++;
                    }
                    j++;//debug
                    //n[i]++;
                    board[x][y]=i+'1';
                    todo.erase(it);
                    flag=1;
                    break;
                }
            }
            if(flag==0)//no cell has only one number
            {
                auto it=todo.begin();
                int x=(*it).x,y=(*it).y;
                int pos=x/3+y/3*3;
                short temp=~(b[pos]|r[x]|c[y]|0xfe00);
                i=0;
                while(temp>0)
                {
                    if((temp&1)==1)
                    {
                        board[x][y]=i+'1';//guess one in the valid number
                        if(solve(board)==0)//succeed
                        {
                            return 0;
                        }
                        //if failed clear the error num
                        for(auto it2=todo.begin();it2!=todo.end();it2++)
                            board[(*it2).x][(*it2).y]='.';
                    }
                    temp=temp>>1;
                    i++;
                }
                return 1;
            }
        }
        return 0;
    }
};