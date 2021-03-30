    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) x = (double)1.0 / x;
        long current_power = 1, required_power = abs(n);
        double val = x;
		// keep squaring value till the current power is less than n, e.g. if n=28
		// x^1 -> x^2 -> x^4 -> x^8 -> x^16 (can't square it further, as 32>28)
		// since val=x^16 now, calculate x^12 in another recursive call & mult with val to get x^28
		// hence, return val * myPow(x, 28 - 16)
        while (current_power * 2 <= required_power) {
            val *= val;
            current_power *= 2;
        }
        return val * myPow(x, required_power - current_power);
    }
