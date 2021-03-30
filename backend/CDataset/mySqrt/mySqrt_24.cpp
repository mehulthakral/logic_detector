class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int strt = 1, end=x, ans;
        while(strt <= end){
            int mid = strt + (end-strt)/2;
            if(mid <= x/mid){
                ans = mid;
                strt = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
        
    }
};
