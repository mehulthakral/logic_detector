class Solution {
public:
    int reverse(int x) {
        int newX = 0;
        
        while (x != 0) {
            if (newX > (INT_MAX-abs(x%10))/10 || newX < (INT_MIN+abs(x%10))/10) 
                return 0;
            newX = newX*10 + x%10;
            x /= 10;
        }
        
        return newX;
    }   
};
