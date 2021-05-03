class Solution { // Binary Search - Normal
public:
    int mySqrt(int x) {
        if(x==0 || x==1) return x;
        int low(1), high(x/2);
        while(low<=high){
            unsigned long long mid(low+(high-low)/2);
            if(mid*mid==x || ((mid+1)*(mid+1)>x && mid*mid<x)) return mid;
            else if(mid*mid<x) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
};
