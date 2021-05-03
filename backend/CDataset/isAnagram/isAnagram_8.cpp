 class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size()!=t.size()){
        return false;
    }
     int arr[26]={0};
     for(int i=0;i<s.size();i++){
         arr[int(s[i]-97)]+=1;
     }
     for(int i=0;i<t.size();i++){
         if(arr[int(t[i]-97)]==0){
              return false;
         }
        arr[int(t[i]-97)]-=1;
     }   
    return true;
    }
};
