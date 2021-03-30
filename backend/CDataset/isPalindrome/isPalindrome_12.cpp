class Solution {
public:
    bool isPalindrome(int x) {
        long long int ans=0,bal,qus=x;
        if(x<0){
            return false;
        }
        if(x<10){
            return true;
        }
        while(x){
            bal = x%10;
            ans = bal+ans*10;
            x = x/10;
        }
        if(ans == qus){
            return true;
        }
        return false;
    }
};
