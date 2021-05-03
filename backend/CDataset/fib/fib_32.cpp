class Solution {
public:int fib(int N) {
       double phi = (1 + sqrt(5)) / 2; 
        return round(pow(phi, N) / sqrt(5)); 
    }
};