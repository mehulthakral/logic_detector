class Solution {
public:
    void rotate(vector<int>& a, int k) {
        int n = a.size();
        k = k%n;
        reverse(a.begin(),a.begin()+n-k);
        reverse(a.begin()+n-k,a.end());
        reverse(a.begin(),a.end());
    }
};
