class Solution {
public:
    int numTrees(int n) {
        unsigned long  c=1;
        for(int i = 1;i < n;  ) c = 2*(++i*2 -1)*c/(i + 1);
        return c;
    }
};
