int mySqrt(int x) {
	long long start = 1, end = x;
	while (start <= end) {
		long long mid = start + (end - start) / 2;
		long long res = mid * mid;
		if (res == x)
			return mid;
		if (res > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start - 1;
}
