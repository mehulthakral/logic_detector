class Solution {
public:

int numTrees(int n) {
    if (n <= 0) return 0;
    
    int result = 0;
    vector<int> array(n + 1, 0);
    
    array[0] = 1;
    for (int i = 2; i <= n; i++) {
        int cur = array[0];
        
        for (int j = 0; j < i - 1; j++) {
            int next = array[j + 1];
            
            for (int k = 0; k <= j + 1; k++) {
                if (k != j)
                    array[k] += cur;
            }
            cur = next;
        }
    }
    for (int r = 0; r < n + 1; r++)
        result += array[r];
    return result;
}
};