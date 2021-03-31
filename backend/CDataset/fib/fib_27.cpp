int fib(int n)
{
	int a=0, b=1;
	for (; n--; a=exchange(b,a+b));
	return a;   
}
