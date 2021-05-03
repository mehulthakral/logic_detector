class Solution {
public:
    int reverse(int x) {
        bool negativeFlag = false;
        
        if (x<0){
            negativeFlag = true;
            
            if ((x <= INT_MAX) && (x > INT_MIN)) x = -x;
            else return 0;
        
        }
        
        int rev_num = 0, prev_rev_num = 0;
        
        while (x != 0){
            int curr_digit = x % 10;
            
            if (rev_num > INT_MAX/10 || (rev_num == INT_MAX / 10 && curr_digit > 7)) return 0;
            if (rev_num < INT_MIN/10 || (rev_num == INT_MIN / 10 && curr_digit < -8)) return 0;
            
            rev_num = (rev_num * 10) + curr_digit;
                                 
            
            if ((rev_num - curr_digit)/10 != prev_rev_num)
                return 0;
            
            prev_rev_num = rev_num;
            x = x / 10;
        }
        
        return (negativeFlag == true) ? -rev_num : rev_num;
		}
};
