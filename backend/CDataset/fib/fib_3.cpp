class Solution {
public:
    int fib(int n) {
        int t1=0;
        int t2=1;
        int total;
        if (n==0)
		{
            return 0;
        }
        else if (n==1)
		{
            return 1;
        }
        else
		{
			for (int i=1; i<n; i++)
			{
				total = t1 + t2;
				t1 = t2;
				t2 = total;
			}
        return total;
        }
    }
};
 
