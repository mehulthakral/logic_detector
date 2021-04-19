class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0) return false;
        
        int a=abs(x);
        long int p=0;
        while(a>0)
        {
            p=(p*10) + (a%10);
            a=a/10;
        }
       return p==x;
    }
};