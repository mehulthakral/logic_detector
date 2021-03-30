int strStr(string haystack, string needle) {
     
    if (needle.empty()) return 0;
    
    int i,j =0;  
    int startOfMatch = INT_MAX;
    
    while (i < haystack.size()){
        
        if (haystack[i] == needle[j]){
            startOfMatch = min(startOfMatch, i); 
            ++j; ++i;
        }
        else{
            if (startOfMatch == INT_MAX) startOfMatch = 0;
            i = ++startOfMatch; 
            j = 0; 
        }
        if (j==needle.size()) return startOfMatch;
    }
    return -1;
     
    
}