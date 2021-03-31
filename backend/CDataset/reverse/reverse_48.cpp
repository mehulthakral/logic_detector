class Solution {
public:
int reverse(int x) {
    if(x==INT_MIN)//solve this situation, we can use x=abs(x)
        return 0;
	int isPositive=1;
	if(x<0)
	{
	    x=abs(x);
	    isPositive=-1;
	}
	int result=0;
	int int_maxp=INT_MAX/10;
	while(x!=0)
	{
		if (result>int_maxp)//don't need to check "result==int_maxp&&q>int_maxq"，because this can't happen (x is type int)
		{
			result=0;
			break;
		}
		else
			result=10*result+x%10;
		x=x/10;
	}
	result=isPositive*result;
	return result;
}
