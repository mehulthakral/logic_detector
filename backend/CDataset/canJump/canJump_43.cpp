class Solution {
public:bool canJump(vector<int>& a) {
        int n = a.size();
        int currrent_max = 0;
        
        for(int i=0; i<n; i++){
            currrent_max = max(currrent_max, i+a[i]);
            if(currrent_max == n-1)
                return true;
            
            if(a[i] == 0 && currrent_max <= i)
                return false;
        }
        return true;
    }
};