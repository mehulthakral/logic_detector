class Solution {
public:
bool isPalindrome(int x) {
if(x<0) return false;
long y=0,z=x;
while(z!=0)
{
y=(y*10)+(z%10);
z/=10;
}
if(y>INT_MAX || y<INT_MIN) return false; //checking overflow
return y==x;
}
};