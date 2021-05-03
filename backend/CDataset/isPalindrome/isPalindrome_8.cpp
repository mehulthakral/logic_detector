class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        if(x == 0)//As log(0) is undefined
            return true;
        
        int n = (int)log10(x) + 1;//Number of digits to represent x
        int d = pow(10, n-1);//divisor to get MSB
        
        while(d != 0)
        {
            if(x/d != x%10)//Compare MSB and LSB
                return false;
            
            x = (x % d)/10;//Remove LSB and MSB from the number
            d /= 100;//As two digits got remved from the number
        }
        return true;
    }
};