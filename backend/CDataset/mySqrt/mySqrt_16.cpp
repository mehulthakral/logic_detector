int mySqrt(int x) {
        if (x == 1)
            return 1;
        
        double result = x / 2, prev = 0;
        while (abs(result - prev) > 0.1)
        {
            prev = result;
            result = (result + x / result) / 2;
        }
        
        return int(result);
    }
