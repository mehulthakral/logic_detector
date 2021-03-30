double myPow(double x, int n) 
{
	auto out{1.0};
	for( ; n; out *= n&1 ? (n>0 ? x : 1.0/x) : 1.0, x *= x, n/=2);
    return out;
}