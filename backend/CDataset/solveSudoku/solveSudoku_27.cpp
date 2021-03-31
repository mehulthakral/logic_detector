class Solution {
public:
    bool ful(vector<vector<char> >& v,int &x,int &y){  //find unassigned location
        for(x=0;x<9;x++)
           for(y=0;y<9;y++)
               if(v[x][y] == '.')
                   return true;
    }
    bool uir(vector<vector<char> > &v,int x,char num){  //is the number used in a row
        for(int i=0;i<9;i++)
            if(v[x][i] == num)
                return true;
        return false;
    }
    bool uic(vector<vector<char> > &v,int y,char num){ // is the number used in the column
        for(int i=0;i<9;i++)
            if(v[i][y] == num)
                return true;
        return false;
    }
    bool uib(vector<vector<char> > &v,int br,int bc,char num){ //is the number used in the box
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(v[i+br][j+bc] == num)
                    return true;
        return false;
    }
    bool issafe(vector<vector<char> > &v,int x,int y,char num){ // if it is safe to put no. in curent position
        return !uir(v,x,num) && !uic(v,y,num) && !uib(v,x-x%3,y-y%3,num);
    }
    bool sudoku(vector<vector<char> > &v){ // check if solution exist or not
        int x,y;
        if(!ful(v,x,y))
            return true;
        for(int i=1;i<=9;i++){
            char c = i+'0';
            if(issafe(v,x,y,c)){
                v[x][y] = c;
                if(sudoku(v))
                    return true;
                v[x][y] = '.';
            }
        }
        return false; 
    }
    void solveSudoku(vector<vector<char>>& v) {
          if(sudoku(v)){
              return;
          }
    }
};