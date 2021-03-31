	// Base cases
	if (n == 0)
        return 1;
    if (n == 1 || x == 0 || x == 1)
        return x;
	
	// Handle negative powers
	// Find positive power and divide 1 by result
    if (n < 0)
    {
		// Handle negative power = INT32_MIN: prevent overflow
        if (n != INT32_MIN)
        {
            auto res = myPow(x, n * -1);
            return 1 / res;
        }else{
			// Find x^ -(INT32_MIN + 1) and multiply with x
            n++;
            auto res = myPow(x, n * -1);
            res *= x;
            return 1/res;
        }
    }
	// Recursion
    auto r1 = myPow(x, n / 2);
    if (n % 2)
        return r1 * r1 * x;
    else
        return r1 * r1;
    }
