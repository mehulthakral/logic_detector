class Solution {
private:
    void computeLPS(string pat,int m,int lps[]) { 
    // length of the previous longest prefix suffix(lps)
    int len=0; 
    lps[0]=0;
    int i=1; 
    while(i<m) { 
        if(pat[i]==pat[len]) { 
            len++; 
            lps[i]=len; 
            i++; 
        } 
        else {
            if(len!=0) len=lps[len-1];
            else { 
                lps[i]=0; 
                i++; 
            } 
        } 
    } 
    } 
public:
    int strStr(string txt, string pat) {
        int c=0;
        int n=txt.length(); 
        int m=pat.length();
        if(m==0) return 0;
        int lps[m];                           // lps --> longest prefix suffix
        computeLPS(pat,m,lps); 
        int i=0,j=0; 
        while(i<n) { 
            if(pat[j]==txt[i]) { 
                j++; 
                i++; 
            }
            if(j==m) { 
                c=1;
                break; 
                j=lps[j-1]; 
            } 
            else if(i<n && pat[j]!=txt[i]) {  // mismatch after j matches 
            // Do not match lps[0..lps[j-1]] characters they will match anyway 
                if(j!=0) j=lps[j-1];
                else ++i;
            } 
        } 
        return c==1 ? (i-j) : -1;
    }
};
