class Solution {
public:
    int reverse(int x) {
        long returnInt = 0;
        while (x)
        {
            returnInt = returnInt*10+x%10;
            x/=10;
        }
        if (returnInt>0)
            return returnInt > INT_MAX ? 0 : returnInt;
        else return returnInt < INT_MIN ? 0 : returnInt;
    }
};