class Solution {
public:
double myPow(double x, int n) {
	return n == 0 ? 1 : n == 1 ? x : n == -1 ? 1 / x : (n & 1) ? x * myPow(x, n - 1) : myPow(x * x, n / 2);
}
};