class Solution {
public:
int mySqrt(int x) {
if(x==0||x==1)
return x;
return (int)(sqrt(x));
}
};