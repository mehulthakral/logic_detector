class Solution {
public:
    bool isPalindrome(int n) {
        if(n<0) return false;
        
        long long rev = 0;
        int copy = n;
        while(n)
        {
            short d = n%10;
            n = n/10;
            rev = rev * 10 + d;
        }
        if(rev == copy) return true;
        return false;
    }
};
