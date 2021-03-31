class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else
        {
            int p=0,y,k;
            y = x;
            while(x > 0)
            {
                k = x%10;
                x = x/10;
                p = p*10 + k;
                if(p > INT_MAX/10)
                    break;
            }
            if(p == y)
                return true;
            else
                return false;
        }
    }
};
