class Solution {
public:
    int numTrees(int n) {
        int sum;
        vector<int> temp;
        temp.push_back( 1 );
        for( int i = 1; i <= n; i++ )
        {
            sum = 0;
            for( int j = 1; j <= i; j++ )
                sum += temp[ j - 1 ] * temp[ i - j ];
            
            temp.push_back( sum );
        }
        return temp[ n ];
    }
};