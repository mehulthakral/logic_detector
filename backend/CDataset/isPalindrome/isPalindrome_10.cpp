class Solution {
public:
    bool isPalindrome(int x) 
    {
        if(x < 0)
            return false;
        
        long lastDigit = 0;
        long reversedNum = 0;
        long copyX = x;
        while(copyX)
        {
            lastDigit = copyX % 10;
            reversedNum = reversedNum * 10  + lastDigit;
            copyX = copyX / 10;
        }

        if( x == reversedNum)
            return true;
        
        return false;
    }
};
