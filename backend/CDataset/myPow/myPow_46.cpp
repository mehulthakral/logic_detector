class Solution {
public:
double myPow(double x, int n) 
{
	auto out{1.0};
	for( ; n; n/=2)
    {
		if(n&1) out *= n>0 ? x : 1.0/x;
        x *= x;
    }
	
    return out;
}
};