class Solution {
public:
    int mySqrt(int x) {
        int i=1;
        for(;i<46341;i++)
        {
            if((i*i)==x)return i;
            if((i*i)>x)return i-1;
            
        }
return i-1;
    }
};