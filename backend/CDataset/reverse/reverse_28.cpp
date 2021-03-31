class Solution {
public:
	int reverse(int x) {
		int sum = 0;
		int y = x;
		while(y!=0){
			if(x>0){
				if((INT_MAX-y%10)/10<sum){
					return 0;
				}
			}else if(x < 0){
				if((INT_MIN-y%10)/10>sum){
					return 0;
				}
			}
			sum = sum*10+y%10;
			y /= 10;
		}
		return sum;
	}
};