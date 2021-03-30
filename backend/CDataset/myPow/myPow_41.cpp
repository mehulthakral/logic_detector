class Solution {
public:
double myPow(double x,long long int n) {
if(n==0)
{ return 1;
}
double ans=1.00;
bool n_positive=true;
if(n<0)
{
n_positive=false;
n*=-1;
}
while(n)
{
if(n%2==1) ans*=x;
n=n/2;
x*=x;
}
if(n_positive) // if n is positive
return ans;
return (1.0/ans); // if n is negative
}
};