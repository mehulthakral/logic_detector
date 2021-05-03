class Solution {
public:
bool isAnagram(string s, string t) {

		if(s.length()!=t.length())return false;
		
        unordered_map<char, int> hash_table;
        for(int i=0;i<s.length();i++){
             if (hash_table.find(s[i]) == hash_table.end()){
                 hash_table[s[i]]=1;
             }else{
                 hash_table[s[i]]++;
             }
        }
        for(int i=0;i<t.length();i++){
             if (hash_table.find(t[i]) == hash_table.end()){
                 return false;
             }else{
                 if(hash_table[t[i]]<=0)return false;
                 hash_table[t[i]]--;
             }
        }
        for (auto x : hash_table){
            if (x.second > 0)return false;
        }
        return true; 
    }
};