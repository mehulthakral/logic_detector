class Solution {
public:
int fib(int N) {
if(N == 1) return 1;
if(N == 0) return 0;
unsigned int a = 0, b = 1, i = 2;
while(i++ <= N) {
b += a;
a = b - a;
}
return b;
}
};