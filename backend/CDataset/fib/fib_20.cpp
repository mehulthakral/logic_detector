class Solution {
public:
    int fib(int N) {
		float z = sqrt(5);
        long long int t = (pow(2,N)*z);
        long long int a = (pow(1+z,N));
        long long int b = (pow(1-z,N));
        return (a-b)/t;
    }
};
