class Solution
{
public:
    int mySqrt(int n)
    {
        if (n < 2) { return n; }
        int root = n / 2;  // initial guess for the root of f(x) = x^2 - n 
        
        while (n / root < root)
        {
            root = (root + n/root) / 2;
        }
        
        return root;
    }
};
