int fib(int n) {
	vector<int> cache(n + 1, -1);
	return fib_impl(n, cache);
}

int fib_impl(int n, vector<int>& cache) {
	if (n < 2) {
		cache[n] = n;
		return n;
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	cache[n] = fib_impl(n - 1, cache) + fib_impl(n - 2, cache);
	return cache[n];
}