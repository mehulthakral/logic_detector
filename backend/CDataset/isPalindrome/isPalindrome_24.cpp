class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        else if(x < 10) return true;
        int digits = (int)ceil(log10(x));
        if(digits == (int)log10(x)) return false;   //For powers of 10
        for(int i = 1, j = digits; i < j; i++, j--)
        {
            int right = (x%(int)pow(10, i))/pow(10, i-1);
            int left = (x%(int)pow(10, j))/pow(10, j-1);
            if(left != right) return false;
        }
        return true;
    }
};
