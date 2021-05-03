class Solution {
public:
int reverse(int x) {
	int result = 0;
	while (x != 0){
		if (INT_MAX / 10 < result||INT_MIN/10>result){
			result = 0;
			break;
		}
		else{
			result = result * 10 + x % 10;
		}
		x /= 10;
	}
	return result;
}
};