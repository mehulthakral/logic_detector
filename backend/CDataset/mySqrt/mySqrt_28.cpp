class Solution {
public:
    int mySqrt(int x) {
        long long mid,left= 1, right= x;
        if(x<2)
            return x;
        while(left<right){
            mid = left+(right-left)/2;
            if(mid*mid== x)
                return mid;
            if(mid*mid > x){
                right = mid;
            }
            else
                left = mid+1;
        }
        return left-1;
    }
};
