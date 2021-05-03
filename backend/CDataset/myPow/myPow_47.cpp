class Solution {
public:
double square(double x)
{
    return x*x;
}

double myPow(double x, int n) 
{
	if(n<0)
		if(n!=INT_MIN)
		{
		   x = 1.0/x;
		   n = -n;
		}
		else
			return square(myPow(x, n/2));
		
	auto out{1.0};        
	for(int m{1<<30}; m; m/=2)
	{
		out *= out;                
		if(m&n) out *= x;
	}

	return out;
}
};