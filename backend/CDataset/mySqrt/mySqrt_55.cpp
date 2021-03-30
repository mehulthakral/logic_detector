class Solution {
public:
    int mySqrt(int x) {
        long int low=0;
        long int high=x;
        while(low<=high){
            long int mid=(low+high)/2;
            long int temp=mid*mid;
            if(temp==x) return mid;
            else if(temp<x)low=mid+1;
            else high=mid-1;
        }
        return high;        
    }
};
