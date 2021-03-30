class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>ans(26,0);
      for(auto i:s)
      {
        ans[i-'a']++;
      }
      for(auto i:t){
        ans[i-'a']--;
      }
      for(auto i:ans)
      {
        if(i!=0)return false;
      }
      return true;
    }
};
