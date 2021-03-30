class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
        {
            return 0;
        }
        vector<int> ret(1,1);
        for(int i = 1; i <= n; i++)
        {
            int result = 0;
            for(int j = 0; j < i; j++)
            {
                result += ret[j] * ret[i-1 - j];
            }
            ret.push_back(result);
        }
        return ret[n];
    }
};