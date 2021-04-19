// @return x^n.
class Solution {
public:
int pow(int x, int n) {
	// ...
	int ret = 1;
	while (n != 0) {
		if (n % 2 == 1) {
			ret *= x;
		}
		x *= x;
		n /= 2;
	}
	return ret;
}

int fib(int n) {
	// matrix:
	// |r00 r01|
	// |r10 r11|
	size_t r00 = 1;
	size_t r01 = 0;
	// r10 and r11 can be ignored, because r01 doesn't depend on them.

	size_t x00 = 1;
	size_t x01 = 1;
	size_t x10 = 1;
	size_t x11 = 0;
	while (n != 0) {
		if (n % 2 == 1) {
			const auto r00_t = r00;
			r00 = r00 * x00 + r01 * x10;
			r01 = r00_t * x01 + r01 * x11;
		}
		const auto x01_x_x10 = x01 * x10;
		x01 = x00 * x01 + x01 * x11;
		x10 = x00 * x10 + x10 * x11;
		x00 = x00 * x00 + x01_x_x10;
		x11 = x01_x_x10 + x11 * x11;

		n /= 2;
	}
	return r01;
}
};