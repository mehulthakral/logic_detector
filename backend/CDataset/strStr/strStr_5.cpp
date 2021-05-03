class Solution {
public:
int strStr(const string& haystack,const string& needle) {
	if (needle == "") return 0;
	return haystack.find(needle);
}
};