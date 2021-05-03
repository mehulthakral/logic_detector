class Solution {
public:
    int strStr(string haystack, string needle) {
        int n= haystack.size();
        int m= needle.size();
        if(m==0){
            return 0;
        }
        int j=0;
        for(int i=0;i<n;i++){
            if(haystack[i]==needle[j]){
                j++;
            }else{
                i=i-j;
                j=0;
            }
            if(j==m){
                return i-j+1;
            }
        }
        return -1;
    }
};
