class Solution {
public:
int numTrees(int n) {
    vector<int> trees(n+1, 1);
    for(int i = 2; i <= n; i++)
    {
        int j = 0, k = i-1;
        for(; j < k; j++, k--)
            trees[i] += (trees[j] * trees[k] * 2);
        if(j == k)
            trees[i] += (trees[j] * trees[k]);
    }
    return trees[n];
}
};