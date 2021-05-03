class Solution
{
public:
    	int numTrees( int n )
    	{
		        int * a =new int[n + 1];
		        a[0] = 0;
		        a[1] = 1;
		        a[2] = 2;
		        a[3] = 5;
		
		for( int i = 4; i <= n; ++i )
		{
			    int current = 2 * a[i - 1] + 2 * a[i - 2];

	    		for( int j = 3; j < i - 1; ++j )
		    	{
			        	current += ( a[j - 1] * a[i - j] );
			    }
			    a[i] = current;
		}
	        	int out = a[n];
	        	delete [] a;
		        return out;
    	}
};