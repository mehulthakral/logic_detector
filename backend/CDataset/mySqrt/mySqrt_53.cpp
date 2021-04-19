class Solution {
public:
int mySqrt(int x) {
        if(x==0) return 0;
        long start=1, end=x;
        while(start<=end)   {
            long middle = (start+end)/2;
            if(middle*middle==x) return middle;
            if(middle*middle<x) start=middle+1;
            else {end=middle-1;}
        }
        return start-1; //start points right next to the answer, hence, we return start-1
    }
};