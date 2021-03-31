//KMP
class Solution {
public:
int strStr(string haystack, string needle) {
int sn = needle.size();
if(sn==0)
return 0;

    int sh=haystack.size();
    
    //pre-compute how many characters can be skipped when a sub-string of needle was matched previously.
    //For the pattern “AAAA”, skip[] is [0, 1, 2, 3]
    //For the pattern “ABCDE”, is [0, 0, 0, 0, 0]
    //For the pattern “AABAACAABAA”, is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]
    //For the pattern “AAACAAAAAC”, is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]         
    
    int skip[sn];
    skip[0] = 0;
    int i = 1, len = 0; 
    while (i < sn) { 
        if (needle[i] == needle[len]) { 
            len++; 
            skip[i] = len; 
            i++; 
        } 
        else{ // (needle[i] != needle[len]) 
            if (len != 0) { 
                len = skip[len - 1]; 
            } 
            else{ // if (len == 0)  
                skip[i] = 0; 
                i++; 
            } 
        } 
    } 
    
    //matching 
            
    i=0;
    len =0;
    for(len=0;len<sh;){
        while(haystack[len]==needle[i] ){
            ++i;
            ++len;
            if(i==sn) return (len-sn);
         }
         
        if(i==0){
            ++len;
            continue;
        }
        else{
            i=skip[i-1];
        }
    }
    return -1;