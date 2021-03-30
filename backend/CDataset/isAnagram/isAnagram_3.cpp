class Solution {
public:
	bool isAnagram(string s, string t) {
		vector<int> chars (26, 0);
		for (auto chr: t) chars[chr - 'a']++;
		for (auto chr: s) chars[chr - 'a']--;
		for (auto num: chars) if ( num != 0 ) return false;
		return true;
	}
};