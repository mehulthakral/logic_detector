//recursion [Runtime: 12 ms, faster than 27.75% ]
class Solution {
public:
    int fib(int n) {
         if (n <= 1) 
            return n; 
         return fib(n-1) + fib(n-2); 
    }
};