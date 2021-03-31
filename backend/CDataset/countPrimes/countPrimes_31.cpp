int check(int n)
{
vectorv1;
if(n < 2)return 0;
v1.assign(n,true);
v1[0] = v1[1] = false;
for(int i=2;i<=sqrt(n);i++)
{
if(v1[i]==true)
{
for(int j=i*i;j<=n;j=j+i)
{
v1[j]=false;
}
}
}
return count(v1.begin(),v1.end(),true);
}