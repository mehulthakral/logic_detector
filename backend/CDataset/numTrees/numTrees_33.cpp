class Solution {
public:
    vector<int> sols = {1, 1, 2};
    int nextSol(int n) {
        // accumulator variable for the result
        int res = 0;
        // and I proceed to consider all the possible occurrences, leveraging pre-computed solutions
        for (int i = 0; i < n; i++) {
            res += sols[i] * sols[n - i - 1];
        }
        return res;
    }
    void expandSols(int n) {
        // helper to expand sol - notice that I start with lower numbers, going up to n
        while (sols.size() <= n) {
            sols.push_back(nextSol(sols.size()));
        }
    }
    int numTrees(int n) {
        // checks if I have already the results in sol, otherwise it expands it
        return n < sols.size() ? sols[n] : (expandSols(n), sols[n]);
    }
};