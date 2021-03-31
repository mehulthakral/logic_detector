class Solution {
private:
    int history[10000] = {};
public:
    int numTrees(int n) {
        if(n<=1) return 1;
        else{
            int count = 0;
            for(int i =1;i<=n ;i++){
                int left_count = history[i-1];
                if(!left_count) {
                    left_count = numTrees(i-1);
                    history[i-1] = left_count;
                }
                int right_count = history[n-i];
                if(!right_count){
                    right_count = numTrees(n-i);
                    history[n-i] = right_count;
                }
                count += left_count * right_count;
            }
            return count;
        }
    }
};