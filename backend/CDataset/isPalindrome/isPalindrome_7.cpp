class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0, int temp=x;
        if(x>=0){
        while(x!=0){
            int rem = abs(x%10);
            rev=(rev*10)+rem;
            x/=10;
            }
            
            if(temp == rev)
                return true;
            else
                return false;
        }
        else
            return false;
        
    }
};
