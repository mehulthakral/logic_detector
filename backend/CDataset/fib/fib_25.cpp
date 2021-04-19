class Solution {
public:    int fib(int n) {
        
		double phi = (1 + sqrt(5)) / 2; 
		return round(pow(phi, n) / sqrt(5));
    
    }
};