int i,j,count=0;
if(needle==haystack){
    return 0;
}
for(i=0;i<haystack.size();i++){
    for(j=0;j<needle.size();j++){
        if(haystack[i+j] == needle[j]){
            count++;
        }
        if(count==needle.size()){
            return i;
        }
        if(haystack[i+j] != needle[j]){
            count = 0;
            break;
        }
    }
}
return -1;