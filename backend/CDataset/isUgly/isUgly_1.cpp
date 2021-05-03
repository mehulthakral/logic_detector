class Solution {
public:
bool isUgly(int n)
{
	if(!n) return false;
	for( ; !(n%2); n/=2);    
	for( ; !(n%3); n/=3);
	for( ; !(n%5); n/=5);
	return n==1;
}
};