class Solution {
public:
int strStr(string haystack, string needle) {
	int n=haystack.length(), m=needle.length();
	for(int i=0;i<n-m+1;i++){
		int j=0;
		while(j<m){
			if(haystack[i+j]==needle[j]) j++;
			else break;
		}
		if(j==m) return i;
	}
	return -1;
}
};