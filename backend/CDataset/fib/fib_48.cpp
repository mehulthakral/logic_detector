#define REP(i,n) for (int i = 0; i < n; i++)
#define mod 1000000007
#define lli long long int
#define N 2

class Solution {
public:
    int fib(int a) {
        
        if(a==0) return 0;
        
        long long int arr[2][2] = {
            {1,1},
            {1,0}
        };
        power(arr,2,a-1);
        
        long long int b[2][1] = {
            {1},
            {0}
        };
        
        long long int ans = arr[0][0]*1 + arr[0][1]*0;
        
        return (int)ans;
    }
private:
    
    long long int arr[N][N], I[N][N];

    void multiply(long long int a[][N], long long int b[][N], int dim)
    {
        long long int res[dim + 1][dim + 1];
        for(int i = 0;i < dim; i++)
       {
           for(int j = 0; j < dim; j++)
           {
                res[i][j] = 0;
                for(int k = 0; k < dim; k++)
                {
                    res[i][j] = res[i][j]%mod + ((a[i][k]%mod) * (b[k][j]%mod))%mod;
                }
           }
       }
       REP(i,dim) REP(j,dim) a[i][j] = res[i][j] ;// since we want to return arr

    }
    void printMat(int arr[][N], int dim)
    {
        REP(i, dim)
        {
            REP(j, dim)
                cout << arr[i][j]%mod << " ";
            cout << endl;
        }
    }

    void power(long long int arr[][N], int dim, int n)
    {
        REP(i, dim)
            {
                REP(j,dim)
                {
                    if(i == j)I[i][j] = 1;
                    else I[i][j] = 0;
                }
            }
        while(n)
        {
            if(n % 2)
            {
                multiply(I, arr, dim);
                n--;
            }
            else
            {
                multiply(arr , arr, dim) ;
                n = n/2;
            }
        }
        REP(i, dim) REP(j, dim) arr[i][j] = I[i][j];
    }
};