class Solution {
public:
    int reverse(int x) {
        long long int rem, ans = 0; 
        while(x > 0 || x < 0){
            rem = x % 10;
            ans = (ans * 10) + rem;
            x /= 10;
        }
        if(ans > INT_MAX || ans < INT_MIN){
            return 0;
        }
        else{
            return ans;
        }  
    }
};
