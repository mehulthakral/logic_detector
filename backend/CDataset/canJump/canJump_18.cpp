class Solution {
public:
bool canJump(vector& a) {

    int jumps = a[0]-1;
    for(int i=1;i<a.size();i++)
    {
        if(jumps<0) return false;
        jumps = max(jumps-1, a[i]-1);
    }
    return true;
}
};