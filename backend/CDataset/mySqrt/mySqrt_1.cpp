class Solution {
public:
    int mySqrt(int x) {
        if(x==0 || x==1)
            return x;
        int ans;
        int start =1;
        int end =x;
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(mid == x/mid)
                return mid;
            else if( mid < x/mid){
                ans = mid;
                start = mid+1;
            }
            else
                end = mid-1;
        }
        return ans;
    }
};
