class Solution {
public:
    int findsqrt(int low, int high, int n){
        if(low<=high){
            long long int mid=low +(high-low)/2;
            if((mid*mid)<=n && (mid+1)*(mid+1)>n) return mid;
            else if((mid*mid)<n) return findsqrt(mid+1,high,n);
            else return findsqrt(low,mid-1,n);
        }
        return low;
    }
    int mySqrt(int x) {
        return findsqrt(0,x,x);
    }
};
