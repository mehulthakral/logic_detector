class Solution {
public:
    vector<bitset<9>> rm, cm, bm; //bitmasks, row, col, block
    void solveSudoku(vector<vector<char>>& board) {
        rm=cm=bm=vector<bitset<9>>(9,bitset<9>(0));
        vector<pair<pair<int,int>,bitset<9>>> blank; //a list of unfilled slots<<row, col>, bitmask of numbers have been guessed for this slot>
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){ //update bitmasks by given numbers
                    int t = board[i][j]-'1';
                    rm[i].set(t);
                    cm[j].set(t);
                    bm[int(i/3)*3+int(j/3)].set(t);
                }
                else blank.push_back(make_pair(make_pair(i,j),bitset<9>(0))); //unfilled slots list
            }
        }
        sort(blank.begin(),blank.end(),[this](pair<pair<int,int>, bitset<9>> &a, pair<pair<int,int>,bitset<9>> &b){return (rm[a.first.first]|cm[a.first.second]|bm[a.first.first/3*3+a.first.second/3]).count()>(rm[b.first.first]|cm[b.first.second]|bm[b.first.first/3*3+b.first.second/3]).count();}); //sort the unfilled slots based on the current bitmasks
        int curr=0, n=blank.size();
        vector<int> prevind; //backtracking previous guesses and bitmasks 
        vector<vector<bitset<9>>> prevrm;
        vector<vector<bitset<9>>> prevcm;
        vector<vector<bitset<9>>> prevbm;
        while(curr<n){
            int row=blank[curr].first.first;
            int col=blank[curr].first.second;
            int blk=blank[curr].first.first/3*3+blank[curr].first.second/3;
            bitset<9> currm=rm[row]|cm[col]|bm[blk]|blank[curr].second; //generate the bitmask for candidates
            //if no candidate left, assume the problem is solvable, there must be a wrong guess happened before and backtrace
            if(currm.count()==9){
                while(curr!=prevind.back()){
                    blank[curr].second.reset();
                    curr--;
                }
                prevind.pop_back();
                rm=prevrm.back();
                prevrm.pop_back();
                cm=prevcm.back();
                prevcm.pop_back();
                bm=prevbm.back();
                prevbm.pop_back();
            }
            //otherwise, we make a guess as the first candidate
            else{
                int t=0;
                while(currm.test(t)) t++;
                currm.set(t);
                board[row][col]='1'+t;
                blank[curr].second.set(t);
                //if there are more candidates, save the current bitmasks and slot index
                if(currm.count()!=9){
                    prevind.push_back(curr);
                    prevrm.push_back(rm);
                    prevcm.push_back(cm);
                    prevbm.push_back(bm);
                }
                //update bitmasks
                rm[row].set(t);
                cm[col].set(t);
                bm[blk].set(t);
                //if there are more candidates, we resort the remaining unfilled slots
                if(currm.count()!=9)
                sort(blank.begin()+curr+1,blank.end(),[this](pair<pair<int,int>, bitset<9>> &a, pair<pair<int,int>,bitset<9>> &b){return (rm[a.first.first]|cm[a.first.second]|bm[a.first.first/3*3+a.first.second/3]).count()>(rm[b.first.first]|cm[b.first.second]|bm[b.first.first/3*3+b.first.second/3]).count();});
                curr++;
            }
        }
        return;
    }
};