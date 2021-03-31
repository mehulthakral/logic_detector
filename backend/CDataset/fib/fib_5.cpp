// formula for nth term in the fibonacci series Fn = {[(√5 + 1)/2] ^ n} / √5 
class Solution {
public:
    int fib(int n) {
         double phi = (1 + sqrt(5)) / 2; 
         return round(pow(phi, n) / sqrt(5));
    }
};
