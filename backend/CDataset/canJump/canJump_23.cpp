/*
Logic: start with last position and backtrack
Catch : 1. if position i can take you to dest, then reaching position is i is your goal
        2. lets say j<i, and (a[j]+j >= i), then your new dest becomes j 
*/
class Solution {
public:
    bool canJump(int a[], int n) {
        int dest = n-1;
        int cur_pos = n-2;
        while(cur_pos >= 0 && dest != 0) {
          if (a[cur_pos] + cur_pos >= dest) {
              dest = cur_pos;
          }
          cur_pos--;
        }
        return (dest == 0 ? true : false);
    }
};