class Solution {
public:
int mySqrt(int x) {
        if (x==0 || x==1)
            return x;
        int l=1,r=x;
        int ans;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            
            if(mid == x/mid)
                return mid;
            if(mid < x/mid)
            {
                l = mid+1;
                ans = mid;
            }
            else
                r = mid-1;
        }
        
        return ans;
    }
};
     
