class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int val = x;
        long int rem = 0;
        while(x)
        {
            rem = rem*10 + x%10 ;
                x =x/10;
        }
        return(rem == val ? true : false);  
    }
};
