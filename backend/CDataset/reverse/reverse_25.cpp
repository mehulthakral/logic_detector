class Solution {
public:
    int reverse(int x) {
        int y=0;
        
        while(x){
            if(INT_MAX/10 < y){
                return 0;
            }
            if(INT_MIN/10 > y){
                return 0;
            }
            
            //As it was given in question that the input is 32 bit integer, if the input number is positive and while reversing it is greater than +2147483647(INT_MAX) then the output should be 0. But if the input number is negetive and while reversing it is less than -2147483648(INT_MIN) then also the output should be 0.
            
            y = y*10 + x%10;
            x = x/10;
        }
        return y;
    }
};
