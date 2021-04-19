class Solution {
public:
double myPow(double x, int n) 
{
    stack<bool> s;
	for(auto m{n}; m; m/=2)
		s.push(m&1);
    
	auto out{1.0};
    for( ; !empty(s); s.pop())
    {
        out *= out;                
        if(s.top()) out *= n>0 ? x : 1.0/x;
    }
	
    return out;
}
};