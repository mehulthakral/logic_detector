template <int N>
struct Fib {
	enum {
		value = Fib<N - 2>::value + Fib<N - 1>::value,
	};
};

template <>
struct Fib<1> {
	enum {
		value = 1,
	};
};

template <>
struct Fib<0> {
	enum {
		value = 0,
	};
};

template <int N>
static inline int fibn(int n)
{
	if (n == N)
		return Fib<N>::value;
	return fibn<N - 1>(n);
}

template <>
int fibn<-1>(int n)
{
	return -1;
}


class Solution {
public:
    int fib(int N) {
        return fibn<30>(N);
    }
};
