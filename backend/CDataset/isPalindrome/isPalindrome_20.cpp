class Solution {
public:
    bool isPalindrome(int x) {
        //Negative numbers handled
        if(x%10<0)
            return false;
        
		int ans=0, rem=0, temp=x;
        //Reversing the integer
		while(temp!=0){
            rem = temp%10;
            temp = temp/10;
            //To prevent overflow
            if(ans > INT_MAX/10 || (ans == INT_MAX/10 && rem>7))
                return false;
            ans = ans*10 + rem;
        }
        return (ans==x);
    }
};
