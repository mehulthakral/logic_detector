  class Solution {
public:
    int strStr(char *haystack, char *needle) {
        int dlen=strlen(haystack);
	    int plen=strlen(needle);
    	int next[26],i,j;
	    for(i=0;i<26;i++){
	    	next[i]=plen+1;   //initialized as pattern length+1,if it's not in the pattern it will not be changed by the following step
    	}
    	for(i=0;i<plen;i++){
        	next[needle[i]-'a']=plen-i; //change the next i which is in the pattern
    	}
	    i=0;
	    j=0;
	    while(i<=dlen-plen){
	    	while(j<plen&&haystack[i+j]==needle[j])j++;
	    	if(j==plen)return i;
	    	else {
	    	    i+=next[haystack[i+plen]-'a'];
	    	    j=0;
	    	}
    	}
	    return -1;
    }
};