class Solution {
public:
    bool isUgly(int num) 
    {
        if(num<=0) return false;
        vector<int> div(3);
        div[0]=2, div[1]=3, div[2]=5;
        for(int i=0; i<3; i++) while(num%div[i]==0) num = num/div[i];
        if(num==1) return true;
        return false;
    }
};
