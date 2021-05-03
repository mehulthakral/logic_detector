class Solution {
public:
    int strStr(char *a, char *b) {
        int len_b = strlen(b);
        int len_a = strlen(a);
        if (len_a < len_b) return -1;
        
        for (int i = 0; i <= len_a-len_b; ++i) {
            int j = 0;
            while(j < len_b && a[j+i] == b[j]) {
                j++;
            }
            if (j == len_b) {
                return i;
            }
        }
        return -1;
    }
};