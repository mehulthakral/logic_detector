//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
//Memory Usage: 8.3 MB, less than 42.43% of C++ online submissions for Fibonacci Number.
int fib(N){
if(N<2) return N;
int a=0,b=1,c=0;
for(int i=2;i<N+1;i++){
c=a+b;
a=b;
b=c;
}
return c;
