class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26]={0};
        for(char ch:s)
        {
            arr[ch-'a']+=1;
        }
        for(char ch:t)
        {
            arr[ch-'a']-=1;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
};