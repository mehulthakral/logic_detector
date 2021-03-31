class Solution{
public:
double myPow(double x,int n){
if(n==0)
{
return 1;
}
double p=1;
int i;
if (n<0)
{
int y=-1n;
x=1/x;
for (i=1;i<=y;i++)
p=px;
}
else
{
for(i=1;i<=n;i++)
p=p*x;
}
return p;
}
};