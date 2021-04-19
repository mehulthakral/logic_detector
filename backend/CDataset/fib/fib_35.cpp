class Solution {
public:
int fib(int n) {
	size_t a = 0;
	size_t b = 1;
	for (size_t i = 0; i != n; ++i) {
		// a, b = a + b, a
		auto tmp = a;
		a += b;
		b = tmp;
	}
	return a;
}
};