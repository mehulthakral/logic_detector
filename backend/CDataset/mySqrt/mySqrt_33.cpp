class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x; // edge case 
        int x0 = x/2, x1 = x0/2+1; 
        while (x1 < x0) {
            x0 = x1; 
            x1 = (x0 + x/x0)/2; 
        }
        return x0; 
    }
};
