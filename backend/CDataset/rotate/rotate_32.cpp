class Solution {
public:
    void rotate(vector<int>& a, int k) {
        if(a.size()<k) k=k-a.size(); // In case If K is much bigger than a.size() .
		
		
        if(a.size()==0 || a.size()==1 || a.size()==-1) return;
        std::reverse(a.begin(),a.end());
        std::reverse(a.begin(),a.begin()+k);
        std::reverse(a.begin()+k,a.end());
      
    
    }
};
