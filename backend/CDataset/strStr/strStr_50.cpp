class Solution {
public:
int strStr(string haystack, string needle) {
int sn = needle.size();
if(sn==0)
return 0;

    int cnt=0;
    int sh=haystack.size();
    int i=0, j,x;
    int search = sh-sn+1;

        for(j=0;j<search;j++){
            x=j;
            while(haystack[x]==needle[i] && x<sh&&i<sn){
                ++i;
                ++cnt;
                ++x;
            }
            if(cnt==sn) return j;
            else {
                i=0;
                cnt=0;
            }
        }   
    return -1;
}
};