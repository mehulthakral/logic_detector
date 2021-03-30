class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        
        while(x != 0){
            // Check overflow
            if(reverse > (INT_MAX/10 - (x%10)/10) || reverse < (INT_MIN/10-(x%10)/10)){
				return 0;
			}
			
			// Calculate reversed integer
            reverse = reverse*10 + x%10;
            x /= 10;
        }
        
        return reverse;
    }
};
